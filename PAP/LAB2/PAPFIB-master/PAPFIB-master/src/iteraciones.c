#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//start, end, chunk, incr
//0, 10, 1, 1
//i: [i*chunk=A, A+chunk-1]
//0, 100, 10, 2
//i: [i*chunk=A, A+chunk-1]
//0: [0, 10]
int main(int argc, char *argv[]){
	if(argc != 5) {
		printf("Usage: ./name start end chunk_size incr\n");
		exit(0);
	}
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	int chunk = atoi(argv[3]);
	int incr = atoi(argv[4]);
	printf("DATA: start->%u, end->%u, chunk->%u, incr->%u\n", start, end, chunk, incr);
	int l = (end-start)/chunk;
	int r = (end-start)%chunk;
	if((end-start) % chunk != 0) l++;
	printf("Size: %u\n", l);
	printf("faltaran: %u\n", r);
	bool myChunks[l];
	for(int i = 0; i < l;++i){
		if(i==l-1){
			printf("ultima: ");
			int s = start+(i*chunk);
			int e = s + chunk-1;
			e = end;
			printf("[%u,%u]\n", s, e);
		}
		else printf("%u->[%u, %u]\n",i ,start+(i*chunk), (start+(i*chunk))+chunk-1);
	}
}
