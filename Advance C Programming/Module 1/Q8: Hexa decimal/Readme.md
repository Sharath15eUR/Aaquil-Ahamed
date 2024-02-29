## Q8: Find the output of the following Consider the compiler is 32-bit machine
```C
#include <stdio.h>
#include <stdint.h>

int main(){
    unsigned int var = 0x12345678;
    unsigned int rev=0;
    
    for(int i=0;i<8;i++){
        rev = (rev<<4) | ((var>>(4*i)) & 0xF);
    }
    
    printf("%X",rev);
    return 0;
}
```

### Output
> 87654321

### Explaination
The code reverses hexadecimal number using bitwise operators
