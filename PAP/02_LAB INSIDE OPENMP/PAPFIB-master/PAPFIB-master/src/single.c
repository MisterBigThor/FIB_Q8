#include "libminiomp.h"
#include "errno.h"


miniomp_single_t miniomp_single;

bool GOMP_single_start (void){
	miniomp_single.singles[ID]++;
	int max = miniomp_single.max;
	if(miniomp_single.singles[ID] > max){
		return __sync_bool_compare_and_swap(&(miniomp_single.max), max, miniomp_single.singles[ID]);
	}
	return false;
}

void initSingle(void){
	LOG("SINGLE: init structures\n");
	miniomp_single.max = 0;
	for(int i = 0;i<MAX_THREADS; ++i) miniomp_single.singles[i] = 0;
	return;
}
void destroySingle(void){
		LOG("SINGLE: free structures\n");
		LOG("SINGLE STATS:\n");
		LOG("	singles reached: %u\n", miniomp_single.max);
		if(miniomp_single.max <= 0) return;
		for(int i = 0; i<MAX_THREADS; ++i){
			LOG("[%u] = %u	", i, miniomp_single.singles[i]);
			if((i % 4 == 0) & (i != 0)) LOG("\n");
		}
		LOG("\n");
		LOG("=============================================\n");
}
