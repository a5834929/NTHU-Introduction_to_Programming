#include <stdio.h>
int coprime(int x, int num);

int main(void)
{
    int num, n;

    printf("Enter an integer:\n");
    scanf("%d", &num);
    printf("Output:\n");

    for(n=2;n<=num;n++)
    {
        coprime(n, num);
        if(coprime(n, num)==1)
        {
            printf("%d  ", n);
        }
        if(!(n%10))
            printf("\n");
    }
    return 0;
}

int coprime(int x, int num)
{
    /*int cnt;
    for(cnt=x;;cnt--)
    {
        if(x%cnt==0 && num%cnt==0)
            return cnt;
    }*/
    while(x && num)
    {
        if(x> num)
            x %= num;
        else
            num %= x;
    }
    int gcd = (num>x)? num : x;
    if( gcd == 1 )
        return 1;
    else
        return 0;
}

