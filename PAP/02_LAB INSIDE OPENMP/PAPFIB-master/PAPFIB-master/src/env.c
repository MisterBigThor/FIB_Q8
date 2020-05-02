#include <unistd.h>
#include "libminiomp.h"

miniomp_icv_t miniomp_icv;


void parse_env(void) {
	char * env = getenv ("OMP_NUM_THREADS");
	if (env == NULL) {
		LOG("LIB: setting nthreads_var ICV to number of cores\n");
		int procs = (int)sysconf( _SC_NPROCESSORS_ONLN );
      		if (procs < 0) miniomp_icv.nthreads_var = 1;
      		else miniomp_icv.nthreads_var = procs;
    	}
	else miniomp_icv.nthreads_var = atoi(env);
    	LOG("LIB: ICV nthreads_var = to %d\n", miniomp_icv.nthreads_var);
}
