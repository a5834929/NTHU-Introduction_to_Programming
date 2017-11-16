#include<stdio.h>
#include<string.h>
#define SPACE "              "

int main(void)
{
    int n, k, K, M, a, b, c;
    int i;

    printf("Enter an integer:");
    scanf("%d", &n);
    printf("Output:\n");

    for(i=0;i<n;i++)
    {
        if(i==0)
            printf("%.*s1 ", n-1-i, SPACE);

        else
        {
            printf("%.*s", n-1-i, SPACE);

            for(k=0;k<=i;k++)
            {
                a=1;
                b=1;
                K=((i-k)>=k)?k:(i-k);
                M=i-K+1;

                for(;M<=i;M++)
                    a*=M;

                for(;K>0;K--)
                    b*=K;

                c=a/b;
                printf("%d ", c);
            }
        }
        printf("\n");
    }
    return 0;
}


