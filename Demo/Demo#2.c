#include<stdio.h>
int main(void)
{
    unsigned int n, a, b1, b2, p, q, r, s, x1, x2, x3, x4;

    printf("Enter an eight-digit number, \n");
    printf("and the program will calculate the sum from 1 to the number:\n");
    scanf("%u", &n);

    a = n/10000;
    b1 = (n+1)%10000;
    b2 = n%10000;

    p = b1*b2%10000;
    q = (b1*b2/10000 + (b1+b2)*a%10000)%10000;
    r = ((b1*b2/10000 + (b1+b2)*a%10000)/10000 + (b1+b2)*a/10000 + a*a%10000)%10000;
    s = (((b1*b2/10000 + (b1+b2)*a%10000)/10000 + (b1+b2)*a/10000 + a*a%10000)/10000 + a*a/10000)%10000;

    x1 = s/2;
    x2 = (s%2*10000 + r)/2;
    x3 = (r%2*10000 + q)/2;
    x4 = (q%2*10000 + p)/2;

    printf("%04u%04u%04u%04u", x1, x2, x3, x4);

    return 0;
}


