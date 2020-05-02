#include "map.h"
#include "libminiomp.h"

map * myMutexesPointer;

int keys; //keys used
int size; //actual array size

void initMap(){
	LOG("Key-value for mutex init.\n");
	myMutexesPointer = malloc(sizeof(map)*INIT_MUTEXES);
	keys = 0;
	size = INIT_MUTEXES;
	for(int i = 0; i < INIT_MUTEXES; ++i){
		myMutexesPointer[i].key = NULL;
		pthread_mutex_init(&myMutexesPointer[i].plock, NULL);
	}
}

void destroyMap(){
	for(int i = 0; i < size; ++i){
		pthread_mutex_destroy(&myMutexesPointer[i].plock);
	}
	LOG("key-value for mutex ending, keys stored: %u \n", keys);
}

void lockPosition(void ** pptr){
	for(int i = 0; i < keys; ++i){
		if(myMutexesPointer[i].key == pptr){
			pthread_mutex_lock(&myMutexesPointer[i].plock);
			LOG("Locking key: %p", pptr );
			return;
		}
	}
	for(int i = 0; i < size; ++i){
		if(myMutexesPointer[i].key == NULL){
			LOG("NEW LOCKING!");
			__sync_fetch_and_add(&keys, 1);
			myMutexesPointer[i].key = pptr;
			pthread_mutex_lock(&myMutexesPointer[i].plock);
			return;
		}
	}
}

void unlockPosition(void **pptr){
	for(int i = 0; i < size; ++i){
		if(myMutexesPointer[i].key == pptr) {
			pthread_mutex_unlock(&myMutexesPointer[i].plock);
			LOG("Unlocking key %p", pptr);
			return;
		}
	}
	LOG("something went wrong!!!\n");
	exit(-1);
}
