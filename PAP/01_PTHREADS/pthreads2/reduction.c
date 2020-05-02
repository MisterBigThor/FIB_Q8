#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

pthread_key_t reductionVar;
int counter = 0;

void do_computation (int numIterations) {
  for (int i = 0; i < numIterations; i++) {
      int tmp = (int)(long) pthread_getspecific (reductionVar);
      pthread_setspecific (reductionVar, (void *)(long) ++tmp);
  }
}

void * compute(void * threadId) {
  pthread_setspecific(reductionVar, 0);
  do_computation((int)(long)threadId * 100);
  printf("Thread %d contributes to reduction with %d\n", 
        (int)(long)threadId, (int)(long)pthread_getspecific(reductionVar));
  pthread_exit(pthread_getspecific(reductionVar));
}

int main () {
  pthread_t threads[numThreads];

  pthread_key_create(&reductionVar, NULL);
  
  for (int t = 0; t < numThreads; t++) {
    pthread_create(&threads[t], NULL, &compute, (void *)(long) t);
  }

  void *status;
  for (int t = 0; t < numThreads; t++) {
    pthread_join(threads[t], &status);
    counter += (int)(long)status;
  }

  printf("Value for reduction variable counter=%d\n", counter);
  pthread_key_delete(reductionVar);
}
