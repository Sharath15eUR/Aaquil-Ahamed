# Q1: Write a C program to determine the given number is odd or even using Bitwise operators. 

### Approch
> Bitwise AND(&) operator the LSB and 1

### Solution
```C
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
```

### Compiler/Environment
Run it the online Compiler - [Odd&Even.C](https://onecompiler.com/c/425pyuwhu)
