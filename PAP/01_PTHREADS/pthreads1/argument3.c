#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define numThreads 5

typedef struct {
    int	thread_id;
    char *message;
} thread_data;

char *messages[2];

void * PrintHello(void *threadArgs) {
    thread_data *my_data = (thread_data *) threadArgs;

    int tid = my_data->thread_id;
    char * msg = my_data->message;
    printf("%s thread #%d\n", msg, tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[numThreads];
    thread_data thread_data_array[numThreads];

    messages[0] = "Hello World!, it's me";
    messages[1] = "Bonjour le Monde!, c'est moi";

for (int t=0; t<numThreads; t++) {
    thread_data_array[t].thread_id = t;
    thread_data_array[t].message = messages[t%2];
    pthread_create (&threads[t], NULL, &PrintHello,  (void *) (thread_data_array+t) );
}

for (int t=0; t<numThreads; t++)
    pthread_join(threads[t], NULL);

printf("Once everything finished!\n");
}
