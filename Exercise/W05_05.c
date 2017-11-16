#include<stdio.h>

int main(void)
{
    int x, y = 10;
    scanf("%d", &x);

    printf("%d", x%10);

    x = x/10;

    while(x>0)
    {
        printf(" + %d*%d", x%10, y);
        x = x/10;
        y = y*10;
    }

    return 0;
}
