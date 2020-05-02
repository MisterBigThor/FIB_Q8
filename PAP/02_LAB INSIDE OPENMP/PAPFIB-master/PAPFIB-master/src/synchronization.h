#ifndef _SYNC
#define _SYNC

#include <pthread.h>

// Default lock for unnamed critical sections
extern pthread_mutex_t miniomp_default_lock;

// Default barrier within a parallel region
extern pthread_barrier_t miniomp_barrier;

void initSync(void);
void updateNumThreads(int numThreads);
void clearSync(void);

// Functions implemented in this module
void GOMP_critical_start (void);
void GOMP_critical_end (void);
void GOMP_critical_name_start (void **pptr);
void GOMP_critical_name_end (void **pptr);
void GOMP_barrier(void);

#endif
