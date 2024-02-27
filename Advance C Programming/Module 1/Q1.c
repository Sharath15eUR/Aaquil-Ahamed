#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    if(n&1) 
      printf("number %d is ODD", n);
    else 
      printf("number %d is EVEN", n);
}
