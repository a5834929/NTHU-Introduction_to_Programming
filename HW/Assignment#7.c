#include<stdio.h>
#include<string.h>

int main(void)
{
    int i, j, d, occur[10] = {0}, initial, max;
    char word[121]={0}, c;

    printf("Input:\n");
    scanf("%120s", word);
    printf("Output:\n");

    for(i = 0; i<=strlen(word);i++)
    {
        occur[word[i]-'A']++;
    }

    i = 0;
    for(initial = 'A';initial <= 'J';initial++)
    {
        printf("%c : %d\n", initial, occur[i]);
        i++;
    }

    for(i = 0, max = 0;i<=9;i++)
    {
        max = (occur[i]>max)?occur[i]:max;
    }

    printf("\n");
    printf("A B C D E F G H I J\n");

    for(d = 0; d<max; d++)
    {
        for(i = 0,j = 0;j<=9; j++, i++)
        {
            if(occur[i]>0)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
            occur[i]--;
        }
        printf("\n");
    }


    return 0;
}
