#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <sys/sysinfo.h>



int r=1;
pthread_mutex_t mutex;
int *partialResults;

struct factorial{
	int id;
	int init;
	int fi;
	int *n;
};


void* f(void *x){
	cpu_set_t set;
	CPU_ZERO(&set);
	CPU_SET((*(struct factorial *)x).id, &set);
	pthread_setaffinity_np(pthread_self(), 8, &set);

	struct factorial* ff = (struct factorial*) x;
	sleep(5);
	partialResults[ff->id] = 1;
	for(int i = ff->init; i < (ff->fi); ++i){
		partialResults[ff->id] = partialResults[ff->id] * (ff->n)[i];
	}
	pthread_exit((void*)&partialResults[ff->id]);
}


int main(int argc, char**argv){
	if(argc != 2) exit(0);
	int NTHREADS = get_nprocs();
	printf("Threads available: %d \n", NTHREADS);
	int *n;
	__int8_t i;

	pthread_t *pth;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&mutex, NULL);

	int factorial = atoi (argv[1]);
	if(factorial < NTHREADS) NTHREADS = factorial;

	n = malloc(sizeof(int)*factorial); 
	pth = malloc(sizeof(pthread_t)*NTHREADS);
	partialResults = malloc(sizeof(int)*NTHREADS);

	struct factorial control[NTHREADS];

	int opsPerThread = factorial/NTHREADS;
	int lastOps = factorial%NTHREADS;

   	for(i = 0; i < factorial; ++i) n[i] = i+1;
	for(i = 0; i < NTHREADS; ++i){
		control[i].id = i;
		control[i].init= i*opsPerThread;
		control[i].fi = (i*opsPerThread) + opsPerThread;
		control[i].n = n;
		if(i+1== NTHREADS) control[i].fi = factorial;
	    pthread_create(&pth[i], &attr, f, (void *)&control[i]);
	}
	void * exit;
   	for(i = 0; i < NTHREADS; ++i){
        	pthread_join(pth[i],&exit);
			printf("%d join\n", *(int*)exit);
			r = r * *(int*)exit;
	}
	printf("factorial de %d = %d\n", factorial, r);
    	return 0;
}
