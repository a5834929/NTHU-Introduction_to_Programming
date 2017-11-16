#include<stdio.h>
#include<ctype.h>
#define STOP '|'

int main(void)
{
    char c, prev;
    long n_chars = 0L;
    int n_lines = 0,n_words = 0,p_lines = 0,inword = 0;

    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';

    while((c=getchar())!=STOP)
    {
        n_chars++;
        if(c=='\n')
           n_lines++;
        if(!isspace(c)&&!inword)
        {
           inword = 1;
           n_words++;
        }
        if(isspace(c)&&inword)
           inword = 0;
           prev = c;
    }
    if(prev!='\n')
       p_lines=1;

    printf("characters = %ld, words = %d, line = %d, partial lines = %d", n_chars, n_words, n_lines, p_lines);




    return 0;
}
