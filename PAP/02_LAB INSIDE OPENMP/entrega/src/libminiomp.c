#include "libminiomp.h"
#include "intrinsic.h"


void init_miniomp(void) __attribute__((constructor));
void fini_miniomp(void) __attribute__((destructor));


void parse_env(void);
void creatThreadMaster(void);

void init_miniomp(void) {
	LOG ("mini-omp is being initialized\n");
	parse_env();

	miniomp_threads = malloc(MAX_THREADS * sizeof(pthread_t));
	miniomp_parallel = malloc(MAX_THREADS * sizeof(miniomp_parallel_t));

	pthread_key_create(&miniomp_specifickey, NULL);

	creatThreadMaster();
	initParallel();
	initSync();
	initMap();
	initSingle();
	initLoop();
}


void creatThreadMaster(void){
	miniomp_parallel_t * miniomp_main = (miniomp_parallel_t *) malloc(sizeof(miniomp_parallel_t));
	miniomp_main->id = -1;
	miniomp_main->nestedLevel = 0;
	miniomp_main->num_threads = miniomp_icv.nthreads_var;
	pthread_setspecific(miniomp_specifickey, (void *) miniomp_main); 

}
void fini_miniomp(void) {
	pthread_key_delete(miniomp_specifickey);

	destroyMap();
	clearSync();
	destroySingle();
	clearLoop();

	LOG("LIB: mini-omp is finalized\n");
}

