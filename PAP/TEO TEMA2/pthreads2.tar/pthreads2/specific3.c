#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define WRONG 

pthread_key_t key;
pthread_key_t key2;

struct test_struct {
    int i;
    float k;
}struct_data;

int setspecificvar () { /* Set specific data for threads */
#ifdef WRONG
    pthread_setspecific (key, &struct_data);
#else
    struct test_struct *s = malloc(sizeof(struct test_struct));
    memset(s, 0, sizeof(struct test_struct));
    pthread_setspecific (key, s);
#endif
    return 0;
}

int changedata (int i, float k) { /* Change specific data for threads */
#ifdef WRONG
    struct_data.i = i;
    struct_data.k = k;
#else
    struct test_struct *struct_data = pthread_getspecific(key);
    struct_data->i = i;
    struct_data->k = k;
#endif
    return 0;
}

int printdata (int t) {  /* print specific data for threads */
    printf ("Address in child%d returned from pthread_getspecific(key):0x%p\n",
            t, (void *)(struct test_struct *)pthread_getspecific(key));
    printf ("Value of members in struct bound to key in child%d - i=%d k=%f\n", 
            t, ((struct test_struct *)pthread_getspecific (key))->i,
            ((struct test_struct *)pthread_getspecific(key))->k);
    printf ("------------------------------------------------------\n");
    return 0;
}

void * child1 () {
    setspecificvar ();
    sleep (1);
    printdata(1);
    changedata(1, 1.111111); /* Should not change the data in child2 */
    printdata(1);

    sleep (2);
    printdata(1);
    changedata(2, 2.222222); /* Should not change the data in child2 */
    printdata(1);
    pthread_exit(NULL);
}

void * child2 () {
    setspecificvar ();
    sleep (2);
    printdata(2);
    changedata(3, 3.333333); /* Should not change the data in child1 */
    printdata(2);

    sleep (2);
    printdata(2);
    changedata (4, 4.444444); /* Should not change the data in child1 */
    printdata (2);
    pthread_exit(NULL);
}

#ifdef WRONG
#else
void key_destroy (void * arg) {
    printf("Invoking key_destroy\n");
    struct test_struct *struct_data = (struct test_struct *) arg;
    free (struct_data); // deallocate data
}
#endif

int main (void) {
    pthread_t tid1, tid2;

#ifdef WRONG
    pthread_key_create (&key, NULL);
#else
    pthread_key_create (&key, key_destroy);
#endif

    pthread_create (&tid1, NULL, &child1, NULL);
    pthread_create (&tid2, NULL, &child2, NULL);
    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);
    pthread_key_delete (key);
    return 0;
}
