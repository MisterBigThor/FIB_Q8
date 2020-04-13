#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

#include "myChrono.c"

#define WRITESIZE 500*1024*1024

const char * USAGE = "./writeToDis pathToWrite\n";

struct timeval tv0, tv1;
double secs;

int main(int argc, char *argv[]){

	if(argc != 2){
		 printf(USAGE);
		 return -1;
	}
	printf("Write to %s\n", argv[1]);

	int fd = open(argv[1], O_CREAT|O_RDWR, S_IRWXU);

	long long written;
	int a[1024];
	memset(a, '*', 1024);
	SETTIME(tv0)
	while(written < WRITESIZE){
		#ifdef _SECUREWRITE
			int w = write(fd, a, sizeof(a));
			if(w != sizeof(a)) perror("error in a write. \n");
			written += w;
		#else
			written += write(fd, a, sizeof(a));
		#endif
	}
	SETTIME(tv1)
	double s = getDif(tv0, tv1);
	double bw = written/s;
	bw = bw/(1024*1024);
	printf("Total time: 	%lf(s)\n", s);
	printf("Bandwidth: 	%.2lf(MBytes/s)\n", bw);
	return 0;

}
