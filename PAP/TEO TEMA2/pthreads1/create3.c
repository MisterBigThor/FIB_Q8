#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

void * PrintHello(void *threadId) {
   long tid = pthread_self();
   printf("Hello World from %ld!\n", tid);
   pthread_exit((void *) tid);
}

int main(int argc, char *argv[]) {
   pthread_t threads[numThreads];


  for (int t=0; t<numThreads; t++) {
    int rc = pthread_create(&threads[t], NULL, &PrintHello, NULL);
    printf("Main created Pthread %d with id %ld\n", t, (long)threads[t]);
    if (rc) {
  printf("Error code from pthread_create(): %d\n", rc);
  exit(-1);
  }
  }
   printf("Done creating threads\n");

   void *status;
   for (int t=0; t<numThreads; t++) {
       pthread_join(threads[t], &status);
       printf("Completed join with thread %ld %ld\n", (long)threads[t], (long)status);
   }

   printf("All threads finished\n");

   return(0);
}
