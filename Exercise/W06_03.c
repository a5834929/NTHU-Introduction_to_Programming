#include<stdio.h>

int main(void)
{
    int n, m, row, col;

    printf("row:");
    scanf("%d", &row);
    printf("column:");
    scanf("%d", &col);

    for(n = 0; n<=row; n++)
    {
            for(m = 0; m<=col; m++)
            {
                printf("*");
            }
        printf("\n");
    }


    return 0;
}
