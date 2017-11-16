#include<stdio.h>
#include<string.h>

int main(void)
{
    int i;
    char word[40];

    scanf("%s", word);
    i=1;
    while(i<=strlen(word))
    {
        printf("%*.*s", strlen(word), i, word);
        printf("\n");
        i++;
    }


    return 0;
}

