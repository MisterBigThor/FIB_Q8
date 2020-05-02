#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>	/* OpenMP */


void randSleep(){
	sleep(rand()%4);
}

void foo() {
	printf("Test 1: Default barriers default threads\n");
	#pragma omp parallel
	{
		printf("First barrier\n");

		#pragma omp barrier

		printf("Second barrier\n");

		#pragma omp barrier
		printf("Third barrier\n");

		#pragma omp barrier
		printf("Last barrier\n");
	}
	printf("Test 2: Default barriers change num_threads\n");
	#pragma omp parallel num_threads(6)
	{
		printf("First barrier\n");
		#pragma omp barrier
		printf("Second barrier\n");
		#pragma omp barrier
		printf("Third barrier\n");
		#pragma omp barrier
		printf("Last barrier\n");
	}
	printf("Test 3: Call and default barrier.\n");
	#pragma omp parallel num_threads(5)
	{
		printf("First randomSleep\n");
		randSleep();
		#pragma omp barrier
		printf("Second randomSleep\n");
		randSleep();
		#pragma omp barrier
	}
}

int main(int argc, char *argv[]) {
    	foo();
}
