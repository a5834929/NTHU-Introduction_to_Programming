#include<stdio.h>

int main(void)
{
    int a, b, c, d, e, f, h, i, n, x;

    printf("num1:");
    scanf("%d", &a);
    printf("num2:");
    scanf("%d", &b);
    printf("num3:");
    scanf("%d", &c);

    x = a*b;
    d = 1;
    e = b;

    h = (c>0)?1:0;

    while(h>=1)
    {
        while(e<=x)
        {
            while(d<=e)
            {
                printf("%3d", d);
                d++;
            }
         printf("\n");
         e+=b;
        }
        h = 0;
    }

    f = a;
    n = 1;

    while(c<=0)
    {
        while(n<=f)
        {
            d = n;
            while(d<=x)
            {
              printf("%3d", d);
              d+=f;
            }
         printf("\n");
         n++;


        }
        c = 1;
    }


    return 0;
}
