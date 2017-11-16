#include<stdio.h>
void hanoi(char source, char target, char buffer, int n);

int main(void)
{
    int a;

    printf("Enter an integer to show the steps of Hanoi Tower\n(enter q to quit):\n");

    while(scanf("%d", &a)==1)
    {
        hanoi('L', 'M', 'R', a);
    }

    return 0;
}

void hanoi(char source, char target, char buffer, int n)
{
    if(n>0)
    {
        hanoi(source, buffer, target, n-1);
        printf("%c --> %c\n", source, target);
        hanoi(buffer, target, source, n-1);
    }
}
