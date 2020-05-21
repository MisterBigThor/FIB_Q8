#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>	/* OpenMP */


void randSleep(){
	sleep(rand()%4);
}
void foo() {
#pragma omp parallel // reduction(+:result)
    {
    for (long i = 0; i < 10; i++) {
        if (i%2) {
            #pragma omp critical(even)
            result_even++;
            }
        else {
            #pragma omp critical(odd)
            result_odd++;
            }
    }

    #pragma omp barrier

    printf("Values for even and odd are %ld and %ld, respectively\n", result_even, result_odd);

    #pragma omp critical
    result += (result_even + result_odd);

    #pragma omp atomic
    result++;

    #pragma omp flush(result)

    #pragma omp barrier
    printf("result = %ld\n", result);

    #pragma omp barrier
    printf("To double check ... result = %ld\n", result);
    }
}

void defaultBarrier() {
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
	printf("Test 2: Default barriers change num_threads\n")
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
    	defaultBarrier();
	foo();
}
