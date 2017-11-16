#include<stdio.h>

int main(void)
{
    unsigned int a, b, c1, c2, d1, d2, p, q, r, s;

    printf("first number:");
    scanf("%u", &a);
    printf("second number:");
    scanf("%u", &b);

    c1 = a/10000;
    c2 = a%10000;
    d1 = b/10000;
    d2 = b%10000;

    p = c2*d2%10000;
    q = (c2*d2/10000 + (c1*d2+c2*d1)%10000)%10000;
    r = ((c2*d2/10000 + (c1*d2+c2*d1)%10000)/10000 + (c1*d2+c2*d1)/10000 + c1*d1%10000)%10000;
    s = ((c2*d2/10000 + (c1*d2+c2*d1)%10000)/10000 + (c1*d2+c2*d1)/10000 + c1*d1%10000)/10000 + c1*d1/10000;


    printf("%04u", s);
    printf("%04u", r);
    printf("%04u", q);
    printf("%04u", p);

    return 0;
}
