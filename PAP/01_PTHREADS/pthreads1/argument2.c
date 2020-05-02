#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

void * PrintHello(void *threadId) {
   int * tid = (int *) threadId;
   printf("Hello World! It's me, thread #%d!\n", *tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[numThreads];
   int argument[numThreads];

   for (int t=0; t<numThreads; t++) {
       argument[t] = t;
       pthread_create(&threads[t], NULL, &PrintHello, (void *) &argument[t]);
   }

   for (int t=0; t<numThreads; t++)
       pthread_join(threads[t], NULL);

   pthread_exit(NULL);
}

