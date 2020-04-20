#ifndef _MAP_H
#define _MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define INIT_MUTEXES 5

typedef struct {
	void * key;
	pthread_mutex_t plock;
} map;

extern map * myMutexesMap[INIT_MUTEXES];

void initMap();
void destroyMap();

void lockPosition(void **key);
void unlockPosition(void **key);

void printMap();

#endif
