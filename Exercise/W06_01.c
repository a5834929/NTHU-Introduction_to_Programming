#include<stdio.h>

int main(void)
{
    int n;

    for(n = 1; n<100; n+=2)
        printf("%3d    %5d\n", n, n*n);
 
    return 0;
}
