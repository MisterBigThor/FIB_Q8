#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <numa.h>
 
double waste_time(long n) {
    double res = 0;
    long i = 0;
    while (i < n * 200000) {
        i++;
        res += sqrt(i);
    }
    return res;
}
 
void *thread_func(void *param) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    /* bind thread to processor 0 */
    CPU_SET(0, &cpuset); 
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
 
    /* waste some time so the work is visible with "top" */
    printf("result: %f\n", waste_time(5000));
 
    /* bind thread to processor 3 */
    CPU_CLR(0, &cpuset);
    CPU_SET(3, &cpuset); 
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
 
    /* waste some more time to see the processor switch */
    printf("result: %f\n", waste_time(5000));

    pthread_exit(NULL);
}
 
int main() {
    pthread_t my_thread;

    printf("Numa available returns %d\n", numa_available());
    printf("Numa numa_num_configured_cpus returns %d\n", numa_num_configured_cpus());
    printf("Numa numa_num_configured_nodes returns %d\n", numa_num_configured_nodes());

    for (int i = 0; i < numa_num_configured_cpus(); i++) 
       	printf("cpu %d in node %d\n", i, numa_node_of_cpu(i));
		pthread_create(&my_thread, NULL, thread_func, NULL);
	    pthread_join(my_thread, NULL);
}
