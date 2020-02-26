#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

void * PrintHello(void *arg) {
   printf("Hello World!\n");
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[numThreads];
   for (int t=0; t<numThreads; t++) {
       int rc = pthread_create(&threads[t], NULL, &PrintHello, NULL);
       if (rc) {
         printf("Error code from pthread_create(): %d\n", rc);
         exit(-1);
       }
   }
   printf("Done creating threads\n");

#if 1
   for (int t=0; t<numThreads; t++) {
       pthread_join(threads[t], NULL);
       printf("Completed join with thread %ld\n", (long)threads[t]);
       }
#else
   pthread_exit(NULL);
#endif

   printf("All threads finished\n");

   return(0); 
}
