#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int r=1;
pthread_mutex_t mutex;

void* f(void *x){
    pthread_mutex_lock(&mutex);
        r = r * *(int *) x;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}


int main(int argc, char**argv){
    int NTHREADS;
    int *n;
    __int8_t i;
    pthread_t *pth;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_mutex_init(&mutex, NULL);
    NTHREADS = atoi (argv[1]);

    n = malloc(sizeof(int)*NTHREADS); //demanar memòria pel vector N
    pth = malloc(sizeof(pthread_t)*NTHREADS); //demanar memòria pel vector pth
    
    for(i = 0; i < NTHREADS; ++i) 
        n[i] = i+1;
    printf("PTHREAD CREATE: \n");
    for(i = 0; i < NTHREADS; ++i)
        pthread_create(&pth[i], NULL, f, (void *)&n[i]);
    printf("PTHREAD JOIN: \n");
    for(i = 0; i < NTHREADS; ++i)
        pthread_join(pth[i], NULL);
    printf("factorial de %d = %d\n", NTHREADS, r);
    return 0;
}