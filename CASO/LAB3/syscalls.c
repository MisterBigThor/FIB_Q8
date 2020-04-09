#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <sched.h>
#include "myChrono.c"

#define N 1000000
struct timeval tv0, tv1;

double max, min, avg, total = 0.0;
int maxI, minI;
void calc(double r, int t){
	if(r > max) {
		max = r;
		maxI = t;
	}
	if(r < min) {
		min = r;
		minI = t;
	}
	total += r;
	if(t != 0) avg = (avg + r)/2;
	else avg = r;
}
void printTime(char * syscall){
	printf("Total elapsed time for %s: 	%lf(s)\n", syscall,total);
	printf("Max time: %lf(s) @ %i\n", max, maxI);
	printf("Min time: %lf(s) @ %i\n", min, minI);
	printf("AVG time: %lf(s)\n", avg);
}
int main(int argc, char *argv[]){
	max, min, avg, total = 0.0;
	for(int i =0 ; i< N; ++i){
		SETTIME(tv0)
		void * r = sbrk(0);
//		printf("sbrk @ %p", r);
		SETTIME(tv1)
		calc(getDif(tv0, tv1), i);
	}
	printTime("sbrk(0)");

	max, min, avg, total = 0.0;
	for(int i =0 ; i< N; ++i){
		SETTIME(tv0)
		sbrk(1);
		SETTIME(tv1)
		calc(getDif(tv0, tv1), i);
	}
	printTime("sbrk(1)");

	max, min, avg, total = 0.0;
	for(int i =0 ; i< N; ++i){
		SETTIME(tv0)
		sched_yield();
		SETTIME(tv1)
		calc(getDif(tv0, tv1), i);
	}
	printTime("sched_yield(1)");

	max, min, avg, total = 0.0;
	for(int i =0 ; i< N; ++i){
		SETTIME(tv0)
		getpid();
		SETTIME(tv1)
		calc(getDif(tv0, tv1), i);
	}
	printTime("getPid(1)");

	max, min, avg, total = 0.0;
	for(int i =0 ; i< N/1000; ++i){
		SETTIME(tv0)
		int r = fork();int status;
		if(r == 0){//no empty child
			exit(0);
		}
		else if(r == -1) perror("error fork");		
		
		else{
			waitpid(r, &status, 0);
		}
		SETTIME(tv1)
		calc(getDif(tv0, tv1),i);
	}
	printTime("fork/waitpid()");
	return 0;

}
