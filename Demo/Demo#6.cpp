#include<stdio.h>
#define SPACE "                "

int main(void)
{
    int i ,j, d;
    char c, ch;

    printf("Enter an uppercase letter:\n");
    scanf("%c", &c);
    ch=c;

    printf("%c", ch);

    for(i=1;i<=(ch-'A'+1);i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c", ch--);
        }

        for(j=1;j<(i-1);j++)
        {
            printf("%c", ch);
        }

        printf("\n");

    }

return 0;
}
