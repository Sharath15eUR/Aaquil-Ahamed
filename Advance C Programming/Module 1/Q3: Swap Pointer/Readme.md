# Q3:  Write a C program to swap two numbers. Use a function pointer to do this operation. 

### Approch
> Swap function uses call by Reference and use a function pointer 

### Solution
```C
#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *y;
  *y = *x;
  *x = temp;
}

int main()
{
  void (*swap_ptr)(int*, int*) = &swap; 
  
  int a , b;
  scanf("%d %d", &a,&b);
  printf("The numbers before swaping :%d %d \n", a, b);
  
  (*swap_ptr)(&a, &b);
  printf("The numbers after swaping :%d %d", a, b);
}
```

### Compiler/Environment
Run it the online Compiler - [Swap_Pointer.C](https://onecompiler.com/c/425q84vgq)
