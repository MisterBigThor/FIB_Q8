#ifndef _CHRONO
#define _CHRONO

#include <sys/time.h>

//struct timeval tv0, tv1;

#define SETTIME(t) gettimeofday(&t, NULL);


double getDif(struct timeval tv0, struct timeval tv1){
	double secs;

	secs = (((double)tv1.tv_sec*1000000.0 + (double)tv1.tv_usec) -
		((double)tv0.tv_sec*1000000.0 + (double)tv0.tv_usec))/1000000.0;

	return secs;
}
#endif
