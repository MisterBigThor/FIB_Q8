#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Mutexes to protect the buffer
pthread_mutex_t producer_lock = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t consumer_lock = PTHREAD_MUTEX_INITIALIZER; 

int buffer; // buffer size 1

#define MAX 10 // maximum number to produce

void *producer() { 
    int number = 0;
    while (1) { 
        number++;    

        pthread_mutex_lock(&producer_lock); 
        printf("Producer : %d\n", number);
        buffer = number;
        pthread_mutex_unlock(&consumer_lock); 

        // Stop if MAX has been produced
        if (number == MAX) {
            printf("Producer done.. !!\n");
            break;
        }
    }
    pthread_exit(NULL);
} 

void *consumer() {
    int number;
    while (1) { 
        pthread_mutex_lock(&consumer_lock); 
        // consume (print) the number in the buffer
        number = buffer;
        printf("Consumer : %d\n", number); 
        pthread_mutex_unlock(&producer_lock); 

        usleep(100000);
        // If the MAX number was the last consumed number, the consumer should stop
        if (number == MAX) {
            printf("Consumer done.. !!\n");
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    int rc;    
    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_mutex_lock(&consumer_lock);
    if ((rc= pthread_create(&consumer_thread, NULL, consumer, NULL)))
        printf("Error creating the consumer thread\n");
    if ((rc= pthread_create(&producer_thread, NULL, producer, NULL)))
        printf("Error creating the producer thread\n");

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
        
    printf("Done..\n"); 
}

