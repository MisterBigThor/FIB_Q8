#include <pthread.h>
#include <stdio.h>

#define N 200
#define numThreads 8

long A[N];        // A is a global variable
typedef struct {
  int min, max;
} param;          // Struct to pass arguments to function compute_array

void *compute_array(void *arg) {
    param *p = (param*)arg;
    int min = p->min; 
    int max = p->max;

    long suma = 0;
    for (int j=min; j<max && j<N; j++) 
        suma += A[j];
    pthread_exit((void *) suma); // complete
}

int main() {
    pthread_t threads[numThreads];
    param p[numThreads];   // complete

    long aux = 0;
    for(int i = 0; i<N; i++){
        A[i] += 1;
        aux += 1;
    }
    printf("Initialized vector with value: %ld \n", aux);
    for (int t=0; t<numThreads; t++) {
       p[t].min = (N/numThreads)* t; 
       p[t].max = ((N/numThreads)* (t+1)); 
       if (t==numThreads-1) p[t].max = N;
       pthread_create (&threads[t], NULL, &compute_array, (void *) &p[t]);
    }

    void * status; // to be used in pthread_join
    long suma = 0;
    for (int t=0; t<numThreads; t++) {
        pthread_join(threads[t], &status);  
        suma += (long) status;        
    }
    printf("All threads finished, final value is: %ld \n", suma);
}
