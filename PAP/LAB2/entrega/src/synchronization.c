#include "libminiomp.h"

/*
File for implement the barrier and critical section (named & unnamed).
Uses a key-value, inicialized in the lib, for contain all the names and locks.
*/

void initSync(void){
	LOG("SYNC: init structures with %u \n", TEAM);
	pthread_barrier_init(&miniomp_barrier, NULL, TEAM);
	pthread_mutex_init(&miniomp_default_lock, NULL);
}

void updateNumThreads(int numThreads){
	LOG("SYNC: Refresh the num_threads with %i, for the default barrier.\n", numThreads);
	pthread_barrier_init(&miniomp_barrier, NULL, numThreads);
	return;
}

void clearSync(void){
	pthread_mutex_destroy(&miniomp_default_lock);
	pthread_barrier_destroy(&miniomp_barrier); // free default barrier
}

//UNNAMED CRITICAL SECTION: Default lock for unnamed critical sections
pthread_mutex_t miniomp_default_lock;

void GOMP_critical_start (void) {
	LOG("Locking the default lock for no-name critical\n");
	pthread_mutex_lock(&miniomp_default_lock);
}

void GOMP_critical_end (void) {
	LOG("Unlocking the default lock for no-name critical\n");
	pthread_mutex_unlock(&miniomp_default_lock);
}

//NAMED CRITICAL SECTION:
void GOMP_critical_name_start (void **pptr) {
	lockPosition(pptr);
	LOG("(%u)CRITICAL_START: name : %p\n",omp_get_thread_num(), pptr);
}

void GOMP_critical_name_end (void **pptr) {
	unlockPosition(pptr);
	LOG("(%u) CRITICAL_END: name : %p\n", omp_get_thread_num(), pptr);
}

//BARRIER: Default barrier, inicialized by the num_threads of each parallel section.
pthread_barrier_t miniomp_barrier;

void GOMP_barrier() {
	LOG("(%i)GOMP_barrier: entering barrier \n", ID);
	pthread_barrier_wait(&miniomp_barrier);
	LOG("(%i)GOMP_barrier: ended the barrier \n", ID);
}
