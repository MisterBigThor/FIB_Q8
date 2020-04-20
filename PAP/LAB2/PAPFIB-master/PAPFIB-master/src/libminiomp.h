#ifndef _LIBMINIOMP_H
#define _LIBMINIOMP_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>

#define MAX_THREADS 32

// Some defines:
#define lock(t) pthread_mutex_lock(&t);
#define unlock(t) pthread_mutex_unlock(&t);
#define trylock(t) pthread_mutex_trylock(&t);

#define ID omp_get_thread_num()
#define TEAM omp_get_num_threads()

#ifdef _DEBUG
#define LOG printf
#else
#define LOG //
#endif

// To implement memory barrier (flush)
//void __atomic_thread_fence(int);
#define mb() __atomic_thread_fence(3)

#include "intrinsic.h"
#include "env.h"
#include "parallel.h"
#include "synchronization.h"
#include "loop.h"
#include "single.h"
#include "task.h"
#include "map.h"
#include "list.h"

extern void updateNumThreads(int numThreads);



#endif
