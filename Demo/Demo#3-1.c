#include<stdio.h>
#include<string.h>
#define LINE "------------------------------------------"
#define SPACE "                                   "

int main(void)
{
    int a ,b, A, B;
    float f;
    char num1[20], num2[20], num3[20], num4[20];

    printf("Enter two integers:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    A = (a>=b)?a:b;
    B = (a>=b)?b:a;
    f = (float)a/b;

    sprintf(num1, "%d", A);
    sprintf(num2, "%d", B);
    sprintf(num3, "%d", a);
    sprintf(num4, "%d", b);

    printf("%.*s%d\n", strlen(num1)+1-strlen(num3), SPACE, a);
    printf("%.*s = %e\n", strlen(num1)+2, LINE, f);
    printf("%.*s%d\n", strlen(num1)+1-strlen(num4), SPACE, b);


    return 0;
}


