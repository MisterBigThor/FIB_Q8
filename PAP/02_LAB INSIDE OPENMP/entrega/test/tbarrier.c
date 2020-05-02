#include <stdio.h>
#include <stdlib.h>
#include <omp.h>	/* OpenMP */

long result=0, result_even=0, result_odd=0;

void foo() {
#pragma omp parallel // reduction(+:result)
	{
	printf("First barrier\n");
	#pragma omp barrier

	printf("Second barrier\n");

	#pragma omp barrier
	printf("Third barrier\n");

	#pragma omp barrier
	printf("Last barrier\n");
	}
}

int main(int argc, char *argv[]) {
	printf("The printf must be in order\n");
    	foo();
}
