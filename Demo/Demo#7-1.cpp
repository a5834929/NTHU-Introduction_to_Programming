#include<stdio.h>
#include<string.h>

int main(void)
{
    int i, j, oc1[10]={0}, oc2[10]={0}, initial, max, d, w;
    char s[121]={0};
    
    scanf("%120s", s);
    
    
    for(i=0;i<=strlen(s);i++)
    {
        if(s[i]>=65){
            oc1[s[i]-'A']++;
        }else{
            oc2[s[i]-'0']++;
        }
    }
    
    
    for(i=0,initial='A';initial<='J';initial++)
    {
        printf("%c:%d  ", initial, oc1[i]);
        i++;
    }
    printf("\n");
    
    for(i=0, max=0;i<=9;i++)
    {
        max = (oc1[i]>max)?oc1[i]:max;
    }
    
    for(d=0;d<max;d++)
    {
        for(i=0,j=0;j<=9;j++,i++)
        {
            if((max-oc1[i])>0)
            {printf("  ");}
            else
            {printf("| ");}
            oc1[i]++;
        }
        printf("\n");
    }
    
    printf("A B C D E F G H I J\n");
    printf("------------------------------------------------------\n");
    


    
    for(w=0,initial='0';initial<='9';initial++)
    {
        printf("%c:%d  ", initial, oc2[w]);
        w++;
    }
    printf("\n");
    
    for(w=0, max=0;w<=9;w++)
    {
        max = (oc2[w]>max)?oc2[w]:max;
    }
    
    for(d=0;d<max;d++)
    {
        for(w=0,j=0;j<=9;j++,w++)
        {
            if((max-oc2[w])>0)
            {printf("  ");}
            else
            {printf("| ");}
            oc2[w]++;
        }
        printf("\n");
    }
    printf("0 1 2 3 4 5 6 7 8 9\n");
    
    
    
    
return 0;
}
