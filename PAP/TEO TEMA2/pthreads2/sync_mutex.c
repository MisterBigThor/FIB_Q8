#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int counter = 0;

void * run () {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main () {
    pthread_t threads[numThreads];
    for (int t=0; t<numThreads; ++t )
        pthread_create (&threads[t], NULL, &run,  NULL);

    for (int t=0; t<numThreads; t++)
        pthread_join(threads[t], NULL);

    pthread_mutex_destroy (&mutex);
    printf("Counter = %i\n", counter);
}
