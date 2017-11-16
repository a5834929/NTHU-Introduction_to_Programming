#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE *fin, *fout;
    fin = freopen("input.txt", "r", stdin);
    fout = freopen("output.txt", "w", stdout);

    char ch;
    char str[1000];
    int i, j, w=0;
    int palindrome;
    int len, max;
    int start, end;
    int count;
    int broke = 0;

    ch = getchar();
    max = ch-'0';
    while(scanf("%s", str)!=EOF){


    len = strlen(str);

    while(len > 1)
     {
        i = 0;
        j = len-1;

        while(j < strlen(str))
        {
            start = i;
            end = j;
            palindrome = 1;
            char shine[100]={0};

            while(start <= end)
            {
                if( str[start] != str[end] )
                {
                    palindrome = 0;
                    break;
                }
                start++;
                end--;
            }
            if( palindrome )
            {
                for(count = i;count<=j;count++,w++){
                shine[w]=str[count];
                }

                if(strlen(shine)==max)
                {

                for(count = i;count<=j;count++)
                {
                printf("%c", str[count]);
                }
                printf("\n");
                broke = 1;
                }
            }
            i++;
            j++;
        }

        if( !broke )
           len--;
        else
           break;
     }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
