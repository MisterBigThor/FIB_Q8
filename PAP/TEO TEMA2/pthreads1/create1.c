#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * PrintHello(void * arg) {
   printf("Hello World!\n");
   //pthread_exit(NULL);
   //exit(0);
   return(0);
}

int main(int argc, char *argv[]) {
   pthread_t thread;
   pthread_create(&thread, NULL, &PrintHello, NULL);

   //pthread_join(thread, NULL);
   //pthread_exit(NULL);
   //exit(0);
   printf("Thread in main has terminated\n");
   return(0); 
}

