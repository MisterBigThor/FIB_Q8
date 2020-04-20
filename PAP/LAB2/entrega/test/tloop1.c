#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <omp.h>	/* OpenMP */

void foo() {
	#pragma omp parallel
	{
		#pragma omp single
		printf("HI, going to execute a dynamic loop\n");

    		#pragma omp for schedule(dynamic,1)
    		for (int i = 0; i < 10; i++)
			printf("Thread %u in iteration %i.\n", omp_get_thread_num(), i);

		#pragma omp barrier
		#pragma omp for schedule(dynamic, 2)
		for(int i = 0; i < 10; ++i)
			printf("Second for Thread %u in iteration %i.\n", omp_get_thread_num(), i);
	}
}

int main(int argc, char *argv[]) {
    foo();
}
