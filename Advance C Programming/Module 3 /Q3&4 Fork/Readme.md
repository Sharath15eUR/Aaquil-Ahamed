# Guess the output for the following program.
### Q3 Code
```C
#include <stdio.h>
#include <unistd.h>

int main(){
  if (fork() && (!fork())) {
    if (fork() || fork()) {
      fork();
    }
  }
  printf("2");

  return 0;
}
```
### Explaination
&& and || gate use short circuit in if statement 

### Output
> 2222222

### Q4 Code
```C
#include <stdio.h>
#include <unistd.h>

int main(){
  if(fork()){
    if(!fork()){
      fork();
      printf("1");
    }
    else{
     printf("2");
    }
  }
  else{
    printf("3");
  }
  printf("4");

  return 0;
}
```
### Explaination
The output of this program can vary each time it's run due to the non-deterministic nature of process scheduling. 
So Lets consider child gets completed first.

### Output
> 3 4 1 4 1 4 2 4
