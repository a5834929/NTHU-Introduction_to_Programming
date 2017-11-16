#include<stdio.h>
#include<string.h>
#define LINE "------------------------------------------"
#define SPACE "                                   "

int main(void)
{
    int a1, a2, b1, b2, c1, c2;
    int A1, A2, B1, B2, C1, C2;
    char numa1[10], numa2[10], numb1[10], numb2[10], numc1[10], numc2[10];
    char numA1[10], numB1[10], numC1[10];

    printf("Enter four integers:\n");
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &b1);
    scanf("%d", &b2);

    c1=a1*b2+a2*b1;
    c2=a2*b2;

    A1=(a1>=a2)?a1:a2;
    B1=(b1>=b2)?b1:b2;
    C1=(c1>=c2)?c1:c2;

    sprintf(numa1, "%d", a1);
    sprintf(numa2, "%d", a2);
    sprintf(numb1, "%d", b1);
    sprintf(numb2, "%d", b2);
    sprintf(numc1, "%d", c1);
    sprintf(numc2, "%d", c2);

    sprintf(numA1, "%d", A1);
    sprintf(numB1, "%d", B1);
    sprintf(numC1, "%d", C1);


    printf("Output:\n");
    printf("%.*s%d", (strlen(numA1)+2-strlen(numa1))/2, SPACE, a1);
    printf("%.*s%d", (strlen(numB1)+2-strlen(numb1))/2+(strlen(numA1)+2-strlen(numa1)-((strlen(numA1)+2-strlen(numa1))/2))+3, SPACE, b1);
    printf("%.*s%d\n", (strlen(numC1)+2-strlen(numc1))/2+(strlen(numB1)+2-strlen(numb1)-((strlen(numB1)+2-strlen(numb1))/2))+3, SPACE, c1);
    printf("%.*s * %.*s = %.*s\n", strlen(numA1)+2, LINE, strlen(numB1)+2, LINE, strlen(numC1)+2, LINE);
    printf("%.*s%d", (strlen(numA1)+2-strlen(numa2))/2, SPACE, a2);
    printf("%.*s%d", (strlen(numB1)+2-strlen(numb2))/2+(strlen(numA1)+2-strlen(numa2)-((strlen(numA1)+2-strlen(numa2))/2))+3, SPACE, b2);
    printf("%.*s%d\n", (strlen(numC1)+2-strlen(numc2))/2+(strlen(numB1)+2-strlen(numb2)-((strlen(numB1)+2-strlen(numb2))/2))+3, SPACE, c2);

    return 0;
}


