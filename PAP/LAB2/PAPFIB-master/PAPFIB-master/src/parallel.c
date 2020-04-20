#include "libminiomp.h"

/*
File for implement the Parallel constructor.
It used an array of pthreads_t, a struct to control the worker of all threads,
and specific key to allocate per thread data.
ToDo: nestedLevel
*/

pthread_t *miniomp_threads;
miniomp_parallel_t *miniomp_parallel;
pthread_key_t miniomp_specifickey;

void initParallel(void){
	pthread_mutex_init(&parallelMutex, NULL);
	for(int i = 0; i < MAX_THREADS; ++i) threadsStatus[i] = UNUSED;
}

void *worker(void *args) {
	miniomp_parallel_t *aux = args;
	pthread_setspecific(miniomp_specifickey, (void *)aux);
	miniomp_parallel_t * aaa = pthread_getspecific(miniomp_specifickey);

	aaa->fn(aaa->fn_data);
	pthread_barrier_wait(aux->teamBarrier);

	pthread_exit(NULL);
	return NULL;
}

void GOMP_parallel (void (*fn) (void *), void *data, unsigned num_threads, unsigned int flags) {
	lock(parallelMutex)
	if(num_threads == 0) num_threads = omp_get_num_threads();
	updateNumThreads(num_threads);

	int nestedLevel = omp_get_level();
	LOG("PARALLEL: creating %d threads to %i in %i\n", num_threads, ID, nestedLevel+1);

	while(num_threads > (MAX_THREADS - miniomp_icv.threads_in_use));

	miniomp_parallel_t * aux = pthread_getspecific(miniomp_specifickey);
	int * w = aux->wait;
	for(int i = 0; i<MAX_THREADS; ++i) w[i] = -1;

	int leaderThread = -1;
	int id = 0; int i =0; int asigned = 0;
	while((i < MAX_THREADS) & (asigned < num_threads)){
		if(threadsStatus[i] == UNUSED){
			if(leaderThread == -1){
				pthread_barrier_init(&miniomp_parallel[i].barrier,NULL, num_threads);
				leaderThread = i;
			}
			miniomp_parallel[i].id = id++;
			miniomp_parallel[i].num_threads = num_threads;
			miniomp_parallel[i].fn_data = data;
			miniomp_parallel[i].fn = fn;
			miniomp_parallel[i].nestedLevel = nestedLevel+1;
			miniomp_parallel[i].teamBarrier = &(miniomp_parallel[leaderThread].barrier);
			pthread_create(&miniomp_threads[i], NULL, &worker,(void *) &miniomp_parallel[i]);
			threadsStatus[i] = USED;
			w[i] = 1;
			asigned++;
		}
		++i;
	}
	miniomp_icv.threads_in_use += num_threads;
	unlock(parallelMutex)

	for(int i = 0; i < MAX_THREADS; i++){
		if(w[i] == 1){
			pthread_join(miniomp_threads[i], NULL);
			threadsStatus[i] = UNUSED;
			miniomp_icv.threads_in_use--;
		}
	}
	LOG("%i end parallel\n", ID);
}

