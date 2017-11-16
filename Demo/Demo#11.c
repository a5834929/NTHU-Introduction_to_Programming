#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int in[1000]={0};
    int i=0, j, len;
    char ch;

    while((ch=getchar())!='\n')
    {
        ungetc(ch, stdin);
        scanf("%d", &in[i++]);
    }

    len=i-1;
    int act=1;
    int temp, cnt=0;

    for(cnt=0;cnt<len;cnt++)
    {
        for(j=0;j<len;j++)
        {
            if(in[j]>in[j+1])
            {
                temp=in[j+1];
                in[j+1]=in[j];
                in[j]=temp;
            }
        }
        for(i=0;i<=len;i++)
        printf("%d ", in[i]);
        printf("\n");
    }
return 0;
}
