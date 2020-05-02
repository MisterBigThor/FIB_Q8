#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

pthread_key_t my_key;

void print_message () {
  int * myID = (int *) pthread_getspecific (my_key);
  printf("Hello World! It's me, thread #%d!\n", *myID);
}

void * PrintHello(void * threadId) {
  pthread_setspecific (my_key, threadId);
  
  // later in the thread code ...
  
  print_message ();
  
  pthread_exit(NULL);
}

int main () {
  pthread_t threads[numThreads];
  int argument[numThreads];

  pthread_key_create (&my_key, NULL);
  
  for (int t = 0; t < numThreads; t++) {
    argument[t] = t;
    pthread_create(&threads[t], NULL, &PrintHello, (void *) &argument[t]);
  }

  for (int t = 0; t < numThreads; t++)
    pthread_join(threads[t], NULL);

  pthread_key_delete(my_key);
}
