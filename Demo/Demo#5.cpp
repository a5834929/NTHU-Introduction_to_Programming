#include<stdio.h>

int main(void)
{
    int row, col, lev;
    int r, c, l, i;
    int R, C, L;

    printf("Rows:");
    scanf("%d", &row);
    printf("Columns:");
    scanf("%d", &col);
    printf("Levels:");
    scanf("%d", &lev);
    printf("Output:\n");

    for(R=0;R<lev;R++)
    {
        printf("Level %d:\n", R+1);

        for(r=1;r<=row;r++)
        {
            for(c=1, i=0;c<=col;c++,i++)
            {
                printf("%d  ", r+row*i+row*col*R);
            }
            printf("\n");
        }
        printf("\n");
    }
return 0;
}
