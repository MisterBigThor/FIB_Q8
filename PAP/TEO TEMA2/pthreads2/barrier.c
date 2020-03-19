#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5
pthread_barrier_t barrier;

//#define REINIT

void * PrintHello(void * arg) {
   printf("Hello World!, it's me thread %d\n", (int)(long) arg);
   int ret = pthread_barrier_wait(&barrier);
   printf("Hello again!, it's still me thread %d with ret=%d\n", (int)(long) arg, ret);

#ifdef REINIT
   if ((int)(long) arg < 3) {
       sleep(4);
       ret = pthread_barrier_wait(&barrier);
       printf("Goodbye from thread %d with ret=%d\n", (int)(long) arg, ret);
   }
#else
   ret = pthread_barrier_wait(&barrier);
   printf("Goodbye from thread %d with ret=%d\n", (int)(long) arg, ret);

#endif

   pthread_exit(NULL);
}

int main() {
   pthread_t threads[numThreads];
   pthread_barrier_init(&barrier, NULL, numThreads+1); // number of threads to wait
   for (int t=0; t<numThreads; t++)
       pthread_create(&threads[t], NULL, &PrintHello, (void *)(long) t );

   printf("Done creating threads\n");

   int ret = pthread_barrier_wait(&barrier);
   printf("All threads arrived to first barrier with ret=%d\n", ret);

#ifdef REINIT
   sleep(2);
   pthread_barrier_init(&barrier, NULL, 3); // number of threads to wait
#else
   ret = pthread_barrier_wait(&barrier);
   printf("Done executing threads with ret=%d\n", ret);
#endif

   pthread_barrier_destroy(&barrier);
   pthread_exit(NULL);
}
