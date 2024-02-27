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
