#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101];
    int num1[100] = {0};
    int num2[100] = {0};
    int num3[200] = {0};
    int i, len1, len2, len_max;
    int carry;

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
    for(i=0;i<=len_max;i++){
        num3[i] = num1[i]+num2[i];
    }

    carry = 0;
    for(i=0;i<=len_max;i++){
        num3[i] = num3[i]+carry;
        carry = num3[i]/10;
        num3[i] = num3[i]%10;
    }

    for(i=len_max-1;i>=0;i--)
        printf("%d", num3[i]);


    printf("\n");

    return 0;
}


