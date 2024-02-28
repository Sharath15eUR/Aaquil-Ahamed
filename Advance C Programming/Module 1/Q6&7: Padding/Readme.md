## Find the output of the following Consider the compiler is 32-bit machine.
```C
#include <stdio.h>

typedef struct
{ int A;
  char B;
  char C;
} InfoData;
int main(int argc, char *argv[])
{
	printf("\n Size of Structure = %d\n\n",sizeof(InfoData));
	return 0;
}
```
### Output
> Size of Structure = 8
### Explaination
size of A is 4(int) and  B & C is 1(char) each b and c is put togather and padded 2 bytes extra to make it 4(size of int)
____________________________________________________________________________________________________________________________________________________

```C
#include <stdio.h>

typedef struct
{
    char A;
    double B;
    char C;
}infoData;

int main(int argc, char* argv[])
{
    printf("\nSize of Structure = %d\n\n", sizeof(infoData));
    return 0;
}

```
### Output
> Size of Structure = 24

### Explaination
size of A is 1(char) padded with 7 bytes extra to make 8(size of double) and size of B is 8(double) and C is also 1(char) also padded with 7 bytes

