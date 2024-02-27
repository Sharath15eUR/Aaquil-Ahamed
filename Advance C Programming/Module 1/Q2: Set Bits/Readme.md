# Q2: Write a C program to count the number of bits set in a number.


### Approch
Bitwise Rightshift(>>) operator the number with Bitwise And(&) operator until the number becomes 0

### Solution
```C
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    int count =0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    printf("The Number set bits : %d", count);
    
}
```

### Compiler/Environment
Run it the online Compiler - [Set_Bits.C](https://onecompiler.com/c/425q5dv58)
