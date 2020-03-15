#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define numThreads 5

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int counter = 0;

void * run () {
  int local = 0;
  for (int i = 0; i < 1000; i++) {
      if (pthread_mutex_trylock(&mutex)==EBUSY) local++;
      else counter++;
      if (local!=0) {
          counter += local;
          printf("Thread %ld accumulated %d\n", pthread_self(), local);
          local = 0;
      }
      pthread_mutex_unlock(&mutex);
  }
}

pthread_mutex_lock(&mutex);
counter += local;
pthread_mutex_unlock(&mutex);

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
