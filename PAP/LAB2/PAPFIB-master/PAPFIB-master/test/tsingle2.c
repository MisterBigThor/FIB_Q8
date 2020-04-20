#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <omp.h>	/* OpenMP */


int main(int argc, char *argv[]) {
	#pragma omp parallel num_threads(30)
	#pragma omp single nowait
	{
		printf("Only one thread here, I'm %u!\n", omp_get_thread_num());
	}
	#pragma omp single nowait
	{
		printf("Second single Only one thread here, I'm %u!\n.", omp_get_thread_num());
	}
	printf("%i: end\n", omp_get_thread_num());
}
