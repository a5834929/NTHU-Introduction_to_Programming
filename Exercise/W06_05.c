#include<stdio.h>

int main(void)
{
    int a, b;

    for(a=1;a<=9;a++)
    {
        for(b=1; b<=a; b++)
        {
            printf("%3d", a*b);
        }

        for(b=1; b>a; b++)
        {
            printf(" ");
        }
    printf("\n");
    }

    return 0;
}
