#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int febo(int n);

int main(void)
{
    int a;
    scanf("%d", &a);

    printf("%d", febo(a));

    return 0;
}

int febo(int n)
{
    int ans;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n>2)
    {
        ans = febo(n-1)+febo(n-2);
        return ans;
    }
}

