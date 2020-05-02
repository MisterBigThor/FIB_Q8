#ifndef _LOOP_H
#define _LOOP_H

#include <list.h>

typedef struct {
	int initLoops; //actual size of loopList
	int actualLoop;
	int reached[MAX_THREADS];
	int ended[MAX_THREADS];
	pthread_mutex_t mutexLoop;
	struct list_head loopList;
}miniomp_loop;

struct loopDescr {
	int id;
	long start;
	long end;
	long incr;
	int schedule;
	long chunk_size;

	int teamThreads;
	int threadInit;

	pthread_barrier_t barrier;
	pthread_mutex_t mutex;

	bool *myChunks;
	int sizeMyChunks;
	struct list_head anchor;
};

#define ws_STATIC 	0
#define ws_STATICCHUNK 	1
#define ws_DYNAMIC 	2
#define ws_GUIDED 	3
#define ws_RUNTIME 	4
#define ws_AUTO 	5


struct loopDescr * initDescriptor(long start, long end, long incr, long chunk_size);
bool allocateIterations(struct loopDescr * miniomp_loop, long *istart, long *iend);
struct loopDescr * getNdescriptor(int n);

void initLoop(void);
void clearLoop(void);

#endif

