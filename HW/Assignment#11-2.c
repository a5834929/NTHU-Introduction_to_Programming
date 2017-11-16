#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int in[1000]={0};
    int out[1000]={0};
    int i, len;
    char ch;

    while((ch=getchar())!='\n')
    {
        ungetc(ch, stdin);
        scanf("%d", &in[i++]);
    }

    len=i-1;
    in[i]=0;

    int inn, outn=0;
    int act=1;

    while(act)
    {
        int min = 1001;
        act = 0;

        for(i=0;in[i];i++)
        {
            if(in[i]<0)
                continue;
            if(min>in[i])
            {
                min = in[i];
                inn = i;
                act = 1;
            }
        }
    out[outn]=min;
    outn++;
    in[inn]=-1;
    }

    for(i=0;in[i];i++)
        printf("%d ", out[i]);

    return 0;
}
