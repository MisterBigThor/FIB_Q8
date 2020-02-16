## OpenMP - PAR

API extension for C, C++. Can create threads, tasks and synchronize them.

Use a fork-join model: a master thread deploy a team of threads that joins a the end of a parallel region. The memory model only guaranteed consistency in certain points.

The compiler defines _OPENMP to perform conditional compilation/coding.

[TOC]

## API Calls

`````c++
//number of threads current team
int omp_get_num_threads();
//id of the thread [0-numThreads-1]
int omp_get_thread_num();
//sets the number of threads to be used in next parallel region
void omp_set_num_threads();
//returns the number of threads that could be used in a paralle region
int omp_get_max_threads();
//number of seconds since arbitrary point
double omp_get_wtime();
`````



## Basic constructs



### Creating threads & accesing data: parallel

`````c++
#pragma omp parallel [clauses]
`````

A internal control variable (ICV) is used to determine the num of threads. By default all variables are marked as shared.

* Clauses:

  num_threads(exp): Ignore ICV and sets the num of threads.

  if(exp): if exp evaluates false -> the parallel only use 1 thread.

  shared(var-list): All threads view the same var (not necessarily the same value).

  private(var-list): All threads have a different var, initialy with undefined value.

  firstprivate(var-list): Same as private, but initialized to the original value.

  reduction(op:var-list): Defines the kind of join for a private var that will perform at the end of the parallel region. (op: +,-,*,|,||,&,&&,^, min,max).

### Synchronization mechanisms: barrier

`````c++
#pragma omp barrier    
//all foo ocurrences after all bar occurrences
#pragma omp parallel
{
    foo();
	#pragma omp barrier    
    bar();
}
`````

Threads cannot proceed past a barrier point until <u>all threads reach the barrier</u> and <u>all previously work is completed</u>. parallel construct have an implicit barrier.

### Synchronization mechanisms: critical

`````c++
#pragma omp critical [(name)]
int x=1, y=0;
#pragma omp parallel num_threads(4)
{
    #pragma omp critical(y)
    y++;
    #pragma omp critical(x)
    x++;
}
`````

Provides a region of mutual exclusion: Only one thread can be working at any given time.

### Synchronization mechanisms: atomic

`````c++
#pragma omp atomic
update -> x+= 1, x= x - foo(), x[index[i]]++;
read -> value = *p;
write -> *p = value;
`````

Ensures that a specific location is accessed atomically, avoiding simultaneous reading and writing threads. More efficient than critical.

Only protects if the expression is one of the specfied in the example.

### Synchronization mechanisms: Locks

Through this API, we can use low-level synchornization

`````c++
omp_lock_t lock;
void omp_init_lock(&lock); //initialize a lock
void omp_set_lock(&lock);
void omp_unset_lock(&lock);
void omp_test_lock(&lock); //won't block
void omp_destroy_lock(&lock);
`````

### Memory consistency: flush

OpenMP don't ensure all time consistency memory model (is a relaxed one). To force a var to read/write from/to the memory; otherwise it can read/write in the thread's temporary view.

````c
#pragma omp flush(list)
````

Synchronization constructs have an associated flush operation.



## Worksharing

A worksharing construct defines a team of threads that execute a certain region of code. Is a better way than split the code with the threads ID.

Is less flexible than tasks, but have lower overhead.

### Worksharing: Loop worksharing

````c++
#pragma omp for[clauses]
	for(int i = 0; i<exp; ++i)
````



## Example: PI parallel Code

In this example we have a 'Data race' with sum variable (by default shared). We can use atomic or critical to avoid it. Another option is to use reduction + for the variable.

````c++
#include <omp.h>
#define NUM_THREADS 2
double step;
static long num_steps = 100000;

void main(){
    int i, id;
    double x, pi, sum =0.0;
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel private(x,i,id)
    {
    	id = omp_get_thread_num();
        for(i=id+1; i<= num_steps; i=i+NUM_THREADS){
            x = (i-0.5)*step;
            #pragma omp critical
            sum = sum + 4.0/(1.0+x*x);
        }
	}
    pi = sum * step;
}
````

