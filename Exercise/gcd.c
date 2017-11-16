#include<stdio.h>

int main(void)
{
     int numer, denom, x, y, gcd;

     while(EOF!=scanf("%d %d", &numer, &denom))
     {
        x=numer;
        y=denom;

        if(x==y) gcd=x;
        if(x%y==0) gcd=(x>y)?y:x;

        while(x%y!=0)
        {
            if(x>y)
            {
                x%=y;
                gcd=x;
            }
            else
            {
                y%=x;
                gcd=y;
            }
        }

        printf("(%d, %d) = %d\n", numer, denom, gcd);

     }

    return 0;
}
