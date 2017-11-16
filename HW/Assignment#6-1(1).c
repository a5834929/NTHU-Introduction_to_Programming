#include<stdio.h>

int main(void)
{
    char ch, a, b, c;

    printf("Input:");
    scanf("%c", &ch);
    printf("Output:\n");

    for(a = 'A';a<=ch; a++)
    {
        for(b = 'A'; b<=ch; b++)
        {
            printf("%c", c=(a>b)?a:b);
        }
    printf("\n");
    }

    return 0;
}
