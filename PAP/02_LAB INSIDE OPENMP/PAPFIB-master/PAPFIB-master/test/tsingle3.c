#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <omp.h>	/* OpenMP */

#define N 1000

int main(int argc, char *argv[]) {
	printf("Thread: %u\n", omp_get_num_threads());
	int r = 0;
	#pragma omp parallel
	{
		for(int i = 0; i < N; ++i){
			#pragma omp single nowait
			{
				//printf("%i Only one thread here, I'm %u!\n", i,omp_get_thread_num());
				#pragma omp atomic
				r++;
			}
		}
	}
	printf("end, expect %i  r=%i \n",N, r);
}
