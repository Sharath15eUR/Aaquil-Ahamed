#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>  

void *HelloThread(void *vargp) 
{ 
  printf("Hello "); 
  pthread_exit(NULL); 
} 

void *WorldThread(void *vargp) 
{ 
  printf("World\n"); 
  pthread_exit(NULL); 
} 

int main(){
  pthread_t tid; 
  int status;
  
  status = pthread_create(&tid, NULL, HelloThread, (void *)&tid);
  if (status) {
    fprintf(stderr, "Error creating thread for Hello\n");
    return 1;
  }
  pthread_join(tid, NULL); 
  
  status = pthread_create(&tid, NULL, WorldThread, (void *)&tid); 
  if (status) {
    fprintf(stderr, "Error creating thread for Hello\n");
    return 1;
  }
  pthread_join(tid, NULL); 
  
  return 0;
}
