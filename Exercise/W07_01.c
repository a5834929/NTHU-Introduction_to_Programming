#include<stdio.h>
#include<ctype.h>


int main(void)
{
    char c;

    while((c = getchar())!='\n')
    {
        if (islower(c))
            c = toupper(c);

        else if(islower(c))
            c = c;
            putchar(c);
    }


    return 0;
}
