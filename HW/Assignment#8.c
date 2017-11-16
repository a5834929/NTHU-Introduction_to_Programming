#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    int i, j;
    int isPalindrome;
    int len;
    int start, end;
    int count;
    int broke = 0;

    scanf("%s", str);

    len = strlen(str);

    while(len > 1)
    {
        i = 0;
        j = len-1;

        while(j < strlen(str))
        {
            start = i;
            end = j;
            isPalindrome = 1;

            while(start <= end)
            {
                if( str[start] != str[end] )
                {
                    isPalindrome = 0;
                    break;
                }
                start++;
                end--;
            }
            if( isPalindrome )
            {
                for(count = i;count<=j;count++)
                {
                    printf("%c", str[count]);
                }
                printf("\n");
                broke = 1;
            }
            i++;
            j++;
        }

        if( !broke )
           len--;
        else
           break;
     }

    return 0;
}
