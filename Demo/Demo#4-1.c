#include<stdio.h>

int main(void)
{
    int n, k, K, M, a, b, c;

    printf("Enter an integer:");
    scanf("%d", &n);
    printf("Output:\n");

    if(n==1) printf("1 ");
    else
    {
        for(k=0;k<=n;k++)
        {
            a=1;
            b=1;
            K=((n-k)>=k)?k:(n-k);
            M=n-K+1;

            for(;M<=n;M++) a*=M;
            for(;K>0;K--) b*=K;
                
            c=a/b;
            printf("%d ", c);
        }
    }
    return 0;
}


