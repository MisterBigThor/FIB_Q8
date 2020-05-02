#include "libminiomp.h"
#include <errno.h>

miniomp_loop ctrlLoops;

bool GOMP_loop_dynamic_start (long start, long end, long incr, long chunk_size, long *istart, long *iend){
	LOG("(%u)LOOP: Dynamic start\n", ID);
	lock(ctrlLoops.mutexLoop);
	ctrlLoops.reached[ID]++;
	if(ctrlLoops.reached[ID] > ctrlLoops.actualLoop){
		ctrlLoops.actualLoop = ctrlLoops.reached[ID];
		struct loopDescr * l = initDescriptor(start, end, incr, chunk_size);
		list_add_tail(&(l->anchor), &(ctrlLoops.loopList));
	}
	unlock(ctrlLoops.mutexLoop);
	return allocateIterations(getNdescriptor(ctrlLoops.reached[ID]-1), istart, iend);
}

void GOMP_loop_end (void) {
//	LOG("(%u)LOOP: loop end\n", ID);
	ctrlLoops.ended[ID]++;
	struct loopDescr * miniomp_loop = getNdescriptor(ctrlLoops.ended[ID]-1);
	pthread_barrier_wait(&miniomp_loop->barrier);
	return;
}

void GOMP_loop_end_nowait (void) {
//	LOG("(%u)LOOP: nowait end\n", ID);
	ctrlLoops.ended[ID]++;
	return;
}

bool GOMP_loop_dynamic_next (long *istart, long *iend) {
	return allocateIterations(getNdescriptor(ctrlLoops.reached[ID]-1), istart, iend);
}
void initLoop(void){
	LOG("LOOP: init data & structures\n");
	ctrlLoops.initLoops = 0;
	pthread_mutex_init(&ctrlLoops.mutexLoop, NULL);
	INIT_LIST_HEAD(&ctrlLoops.loopList);
	for(int i = 0; i<MAX_THREADS;++i) ctrlLoops.reached[i] = 0;
	for(int i = 0; i<MAX_THREADS;++i) ctrlLoops.ended[i] = 0;
}

void clearLoop(void){
	LOG("LOOP STATS:\n");
	LOG("	loops reached: 	 %i\n", ctrlLoops.initLoops);
	LOG("	loops completed: %i\n", ctrlLoops.actualLoop);
	LOG("[i] = reached ended\n");
	for(int i = 0; i < MAX_THREADS; ++i){
		LOG("[%u] = %u %u	", i, ctrlLoops.reached[i], ctrlLoops.ended[i]);
		if((i % 4==0) & (i != 0)) LOG("\n");
	}
	LOG("\n");
	LOG("=============================\n");
	LOG("LOOP: clear data & structures\n");
	pthread_mutex_destroy(&ctrlLoops.mutexLoop);
}

struct loopDescr * initDescriptor(long start, long end, long incr, long chunk_size){
	struct loopDescr * miniomp_loop = malloc(sizeof(struct loopDescr));
	int l = (end-start)/chunk_size ;
	if ((end-start)%chunk_size != 0) l++;
	miniomp_loop->myChunks = malloc(sizeof(bool)*l);
	miniomp_loop->sizeMyChunks = l;
	for(int i = 0; i< l; ++i) miniomp_loop->myChunks[i]=false;
	miniomp_loop->id = 100 + ctrlLoops.initLoops;
	miniomp_loop->start = start;
	miniomp_loop->end = end;
	miniomp_loop->incr = incr;
	miniomp_loop->schedule = ws_DYNAMIC;
	miniomp_loop->chunk_size = chunk_size;
	miniomp_loop->teamThreads = TEAM;
	miniomp_loop->threadInit = ID;

	pthread_barrier_init(&(miniomp_loop->barrier),NULL,TEAM);
	pthread_mutex_init(&(miniomp_loop->mutex), NULL);
	LOG("(%u)LOOP: init descriptor for %i chunks\n",ID, l);
	ctrlLoops.initLoops++;
	return miniomp_loop;
}
bool allocateIterations(struct loopDescr * miniomp_loop, long *istart, long *iend){
	lock(miniomp_loop->mutex)
	int i = 0;
	while(i < miniomp_loop->sizeMyChunks){
		if(!miniomp_loop->myChunks[i]){
			*istart = miniomp_loop->start + (i*miniomp_loop->chunk_size);
			if(*istart+(miniomp_loop->chunk_size) >	miniomp_loop->end) *iend = miniomp_loop->end;
			else *iend = *istart+(miniomp_loop->chunk_size);
			miniomp_loop->myChunks[i] = true;
			LOG("(%u)LOOP: assigned [%li, %li]\n",ID, *istart, *iend);
			unlock(miniomp_loop->mutex)
			return true;
		}
		++i;
	}
	LOG("(%u)LOOP: No more iterations left\n", ID);
	unlock(miniomp_loop->mutex)
	return false;
}


struct loopDescr * getNdescriptor(int n){
	struct list_head * list = list_first(&ctrlLoops.loopList);
	while(n>0){
		list = list->next;
		n--;
	}
	struct loopDescr * ret = list_entry(list,struct loopDescr,anchor);
	//LOG("LOOP:Select %i\n", ret->id);
	return ret;
}












// Only implement this if really needed, i.e. you find a case in which it is invoked

/* The GOMP_parallel_loop_* routines pre-initialize a work-share construct
   to avoid one synchronization once we get into the loop. The compiler 
   does not invoke the *_start routine for the work-share. And of course, 
   the compiler does not invoke GOMP_loop_end. These routines should create 
   the team of threads to execute the work-share in parallel */

void
GOMP_parallel_loop_dynamic (void (*fn) (void *), void *data,
                            unsigned num_threads, long start, long end,
                            long incr, long chunk_size, unsigned flags)
{
  printf("TBI: What another mess! Directly starting a parallel and a non-static for worksharing construct! I am lost!\n");
  // Here you should pre-initialize the work-sharing structures as done in 
  // GOMP_loop_dynamic_start; only the master thread is doing this, the other
  // threads in the team do not reach this point 
  GOMP_parallel (fn, data, num_threads, flags);
}


