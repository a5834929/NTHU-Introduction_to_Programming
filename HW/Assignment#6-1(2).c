#include<stdio.h>

int main(void)
{
    char ch, a, b;
    int row, i, j, var1, var2;

    printf("Input:");
    scanf("%c", &ch);
    printf("Output:\n");

    var1 = 0;
    var2 = 0;

    for(row = 0; row<=(ch-65); row++)
    {
        b = 'A'+var2;
        for(j = 0; j<row;j++)
        {
            printf("%c", b);
        }

        a = 'A'+var1;
        for(i = (ch-64); a<=ch; i--)
        {
            printf("%c", a);
            a++;
        }
    var1++;
    var2++;
    printf("\n");
    }
    return 0;
}
