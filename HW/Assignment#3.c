#include<stdio.h>
#include<string.h>
#define LINE "------------------------------------------"
#define SPACE "                                   "
int main(void)
{
    int x, y, z, w;
    float a;
    char num1[12], num2[12];

    printf("Enter two integers:\n");
    scanf("%d", &x);
    scanf("%d", &y);

    z = (x>=y) ? x : y;
    w = (x>=y) ? y : x;

    sprintf(num1, "%d", z);
    printf("\n");
    printf("%.*s", 1, SPACE);
    printf("%s\n", num1);

    a = (float)z/w;

    printf("%.*s = %e\n", strlen(num1)+2, LINE, a);

    sprintf(num2, "%d", w);
    printf("%.*s", ((strlen(num1)+2) - strlen(num2))/2, SPACE);
    printf("%s", num2);

    return 0;
}
