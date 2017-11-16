#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[101] = {0};
    int num1[100] = {0};
    int num2[100] = {0};
    int num3[200] = {0};
    int len1, len2, len_max;
    int i, d;

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
        if(num1[i]<num2[i]){
            num3[i] = num1[i]+10-num2[i];
            num1[i+1] = num1[i+1]-1;
        }
        else
            num3[i] = num1[i]-num2[i];
    }

    for(i=100;i>=0;i--)
        if(num3[i]!=0)
            break;

    for(d=i;d>=0;d--)
        printf("%d", num3[d]);

    printf("\n");

    return 0;
}


