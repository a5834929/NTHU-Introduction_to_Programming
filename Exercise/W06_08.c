#include<stdio.h>
#include<string.h>

int main(void)
{
    int i, j;
    char word[128];

    scanf("%s", word);

    i = strlen(word)-1;

    for(j=i;j>=0;j--)
    {
        printf("%c", word[j]);
    }


    return 0;
}
