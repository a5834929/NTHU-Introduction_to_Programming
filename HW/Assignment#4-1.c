#include <stdio.h>

int main (void)

{
    int n, m, N, a, b, c, x, y;

    printf("Enter two positive integers to calculate the combination:\n");
    printf("n=");
    scanf("%d", &n);
    printf("m=");
    scanf("%d", &m);

    x = ((n-m)>m)?(n-m):m;
    y = ((n-m)>m)?m:(n-m);
    N = n - y + 1;

    a = 1;
    while (N<=n)
    {
        a = a*N;
        N = N+1;
    }

    b = 1;
    while (y>0)
    {
        b = b*y;
        y = y-1;
    }

    c = a/b;

    printf("The combination is :%d\n", c);


return 0;

}

