#include<stdio.h>
void print0(void);
void print1(void);
int main(void)
{
    print0();
    print0();
    print1();
    print1();

    return 0;
}

void print0(void)
{
    printf("oooo\n");
    printf("o  o\n");
    printf("o  o\n");
    printf("oooo\n");
}

void print1(void)
{
    printf("oo \n");
    printf(" o \n");
    printf(" o\n");
    printf("ooo\n");
}
