#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numThreads 5

typedef struct {
  int thread_id;
  char message[32];
} perthread_data;

pthread_key_t my_key;

void my_key_destroy (void * arg) {
  perthread_data * mine = (perthread_data *) arg; 
  printf("Destroying key for thread %d\n", mine->thread_id);
  free (arg); // deallocate data
}

void print_message () {
  perthread_data * mine = pthread_getspecific (my_key);
  printf("%s %d!\n", mine->message, mine->thread_id);
}

void * PrintHello(void * threadId) {
  int id = (int)(long) threadId;

  perthread_data * mine = (perthread_data *) malloc(sizeof(perthread_data));
  mine->thread_id = id;
  if (id%2) strcpy(mine->message, "Hello World!, it's me");
  else strcpy(mine->message, "Bonjour le Monde!, c'est moi");

  pthread_setspecific (my_key, (void *) mine);
  
  // later in the thread code ...
  
  print_message ();
  
  pthread_exit(NULL);
}

int main () {
  pthread_t threads[numThreads];

  pthread_key_create (&my_key, my_key_destroy); // per-thread attribute key
  
  for (int t = 0; t < numThreads; t++)
    pthread_create(&threads[t], NULL, &PrintHello, (void *)(long) t);

  for (int t = 0; t < numThreads; t++)
    pthread_join(threads[t], NULL);

  pthread_key_delete(my_key);
}

