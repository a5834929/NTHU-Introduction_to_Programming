#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double calculate(void);

int main(void)
{
    printf(" = %lg\n", calculate());
    return 0;
}

double calculate(void)
{
    char c;
    int x, y, z;

    while((c=getchar())!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='\n'&&!isdigit(c));

    if(isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%d", &x);
        printf("%d", x);
        return x;
    }

    else if(c=='\n')
        return 0;

    else
    {
        putchar('(');
        y=calculate();
        putchar(c);
        z=calculate();
        putchar(')');

        if(c=='+') return y+z;

        if(c=='-') return y-z;

        if(c=='*') return y*z;

        if(c=='/')
        {
            if(z==0)
            {
                printf("ERROR; the denominator can't be 0.\n");
                return 0;
            }
            else
                return y/z;
        }
    }
}
