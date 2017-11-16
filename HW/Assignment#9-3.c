#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[101];
    int num1[100] = {0};
    int num2[100] = {0};
    int num3[200] = {0};
    int i, j, k;
    int len1, len2, len_max;
    int carry = 0;


    scanf("%100s", str);
    len1 = strlen(str);
    for(i=0;i<=len1;i++){
        num1[len1-i-1]= str[i]-'0';
    }

    scanf("%100s", str);
    len2 = strlen(str);
    for(i=0;i<=len2;i++){
        num2[len2-i-1]= str[i]-'0';
    }

    len_max = (len1>=len2)?len1:len2;
    for(i=0;i<len_max;i++){
        for(j=0;j<len_max;j++){
            k = i+j;
            num3[k] = num1[i]*num2[j] + num3[k];
        }
    }

    carry = 0;
    for(k=0;k<len_max;k++){
        num3[k] = num3[k]+carry;
        carry = num3[k]/10;
        num3[k] = num3[k]%10;
    }

    for(k=99;k>=0;k--)
        if(num3[k]!=0)
            break;

    for(i=k;i>=0;i--)
        printf("%d", num3[i]);

    printf("\n");

    return 0;
}


