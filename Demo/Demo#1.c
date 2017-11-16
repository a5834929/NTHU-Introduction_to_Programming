#include <stdio.h>

void print0(void);
void print1(void);
int main(void)
{
    print0();

    return 0;
}

void print0(void)
{
    printf("CS15\n");
    print1();
    printf("100062236\n");
}

void print1(void)
{
    printf("NTHU\n");
}

