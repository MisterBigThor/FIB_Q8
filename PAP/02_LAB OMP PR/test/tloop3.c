#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <omp.h>	/* OpenMP */

long result=0;

void foo() {
	#pragma omp parallel
    	{
    		#pragma omp for schedule(dynamic,4)
	    	for (long i = 0; i < 10; i++){
			#pragma omp atomic
			result += 5;
		}

    		#pragma omp single
    		printf("First result = %ld\n", result);

		#pragma omp for schedule(dynamic,40)
	    	for (long i = 0; i <= 1000; i++){
			#pragma omp atomic			
			result += 3;
		}
    		#pragma omp single
    		printf("Second result = %ld\n", result);

		#pragma omp for schedule(dynamic,24)
	    	for (long i = 5; i <= 100; i=i+2){
			#pragma omp atomic
			result += 3;
		}
    		#pragma omp single
    		printf("Last result = %ld, expect 3197\n", result);
	}
}

int main(int argc, char *argv[]) {
    foo();
}
