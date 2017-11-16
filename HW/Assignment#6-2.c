#include<stdio.h>

int main(void)
{
    char ch, a, b, c;

    printf("Input:");
    scanf("%c", &ch);
    printf("Output:\n");

    for(a = ch;a>64; a--)
    {
        for(b = ch; b>64; b--)
        {
            printf("%c", c=(a>b)?b:a);
        }
    printf("\n");
    }

    return 0;
}
