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
