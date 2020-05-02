#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <omp.h>	/* OpenMP */



int main(int argc, char *argv[]) {
	#pragma omp parallel
	for(int i = 0; i< 10; ++i){
		#pragma omp single nowait
		sleep(3);
	}
}
