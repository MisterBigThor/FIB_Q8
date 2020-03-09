#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define numThreads 8

#define INC_TO 1000000 // one million...

int global_int = 0;
int finished=0;
int towait=0;

void * thread_routine( void *arg ) {
	int id = (int)(long)arg;

	for (long i = 0; i < INC_TO; i++) {
		//global_int++; // data race problem
		__sync_fetch_and_add( &global_int, 1 );
	}

	if (id == 0) { sleep(2); towait=1; sleep(2); finished=1;}
        printf("Thread %d is finishing\n", id);

	if (id != 0) while(finished==0); 
        printf("Thread %d is exiting \n", id);

	pthread_exit(NULL);
}

int main() {
	pthread_t threads[numThreads];

	for (int i = 0; i < numThreads; i++)
	    pthread_create(&threads[i], NULL, thread_routine, (void *)(long) i);

	while (towait == 0); 

        printf("Main thread waiting for threads to finish\n");
	for (int i = 0; i < numThreads; i++) 
		pthread_join(threads[i], NULL);
	
	printf( "After doing all the math, global_int value is: %d (expected %d)\n", global_int, INC_TO * numThreads );

	return 0;
}
