#include<stdio.h>

int main(void)
{
    int n;

    printf("Enter a positive integer(enter q to quit):\n");

    while(1){

    while(scanf("%d", &n)==1){
        if(n>0){
            printf("%d\n", n*n);
            printf("Enter another positive integer\n");
        }
        else{
            printf("%d is not positive.\n", n);
            printf("Enter a POSITIVE integer(enter q to quit):\n");
            }
    }

    if((n=getchar())!='q'){
        putchar(n);
        printf(" is not an integer.\n");
        printf("Enter a positive INTEGER(enter q to quit):\n");
    }
    else
        break;
    }
    printf("Bye!\n");

    return 0;
}

