#include <pthread.h>                                                            
#include <stdio.h>                                                              
#include <unistd.h>                                                             
#include <stdlib.h>
#include <numa.h>

#define NUM_THREADS 4
#define YIELD 0
                                                                                
void *thread_body(void *arg) {                                                       
  int id = (int)(long) arg;
  cpu_set_t cpuset;

  CPU_ZERO(&cpuset);
  /* bind printer threads to processor 1 */
  CPU_SET(1, &cpuset);
  pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
                                                                                
  while (1) {                                                                   
    printf("%d", id);
#if YIELD
    pthread_yield();                                                        
#endif
  }                                                                             
}                                                                               

int main() {                                                                        
  pthread_t thread_id[NUM_THREADS];
  cpu_set_t cpuset;

  CPU_ZERO(&cpuset);
  /* bind master thread to processor 0 */
  CPU_SET(0, &cpuset);
  pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

  for (int i=0; i<NUM_THREADS; i++)
      if (pthread_create(&thread_id[i], NULL, thread_body, (void *)(long) i) != 0) {                     
          perror("pthread_create() error");                                           
          exit(1);                                                                    
      }                                                                             
                                                                                
  sleep(4);                                                                     

  printf("\n");
                                                                                
  exit(0); /* this will tear all threads down */                                
}                                 
