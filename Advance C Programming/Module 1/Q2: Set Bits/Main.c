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
