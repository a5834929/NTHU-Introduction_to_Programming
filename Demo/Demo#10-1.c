#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int seq(int n, int m);
int cal(int n, int m);

int main(void)
{
    int a, b;

    scanf("%d", &a);
    b = a;

    while(a>1)
    {
        printf("(");
        a--;
    }

    seq(1, b);
    printf("=%d", cal(1, b));
    return 0;
}

int seq(int n, int m)
{
    if(n<=m)
    {
        if(n==1)
            printf("%d", n);
        if((n%2)==1&&n>1)
            printf("+%d)", n);
        if((n%2)==0&&n>1)
        printf("-%d)", n);
    }

    else
    return 0;

    seq(n+1, m);
}

int cal(int n, int m)
{
    if(m==1)
        return 1;
    else
    {
        if((m%2)==1)
            return (m+1)/2;
        else
            return -(m+1)/2;
    }

}


