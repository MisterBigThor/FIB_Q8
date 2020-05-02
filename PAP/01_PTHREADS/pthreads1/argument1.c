#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

void * PrintHello(void *threadId) {
#if 1
   int *tid = (int *) threadId;
   printf("Hello World! It's me, thread #%d!\n", *tid);
#else
   int tid = (int)(long) threadId;
   printf("Hello World! It's me, thread #%d!\n", tid);
#endif
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[numThreads];

   for (int t=0; t<numThreads; t++) 
#if 1
       pthread_create(&threads[t], NULL, &PrintHello, (void *)&t);
#else
       pthread_create(&threads[t], NULL, &PrintHello, (void *)(long)t);
#endif

   for (int t=0; t<numThreads; t++)
       pthread_join(threads[t], NULL);

   pthread_exit(NULL);
}
