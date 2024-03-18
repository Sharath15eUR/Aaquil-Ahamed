# Q9: Write a C program to demonstrate the use of Mutexes in threads synchronization  

### Explaination
When Threads are executing in parallel, concurrent access to shared resources can cause data inconsistencies and race conditions. Mutexes provide essential protection by allowing only one thread to access critical sections at a time, ensuring data integrity and preventing conflicts

### Solution
```C
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ITERATIONS 10000

int shared_var = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void* arg) {
  
  for (int i = 0; i < ITERATIONS; ++i){
    pthread_mutex_lock(&mutex); 
    shared_var++; 
    pthread_mutex_unlock(&mutex); 
  }
  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; ++i) 
    pthread_create(&threads[i], NULL, thread_function, NULL);

  for (int i = 0; i < NUM_THREADS; ++i) 
    pthread_join(threads[i], NULL);

  pthread_mutex_destroy(&mutex);
  printf("The value of the shared Resource is: %d\n", shared_var);

  return 0;
}
```

### Compiler/Environment
Run it the online Compiler - [Mutex.C](https://replit.com/@AaquilAhamed/Q9-Mutex#main.c)
