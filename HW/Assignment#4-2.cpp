#include<stdio.h>

int main(void)
{
   int i = 1, j = 1, a, b;

   printf("Enter two integers to show the multiplication table:\n");
   scanf("%d", &a);
   scanf("%d", &b);

   while(i<=a)
   {
      while(j<=b)
    {
      printf("%3d", i*j);
      j++;
      }
   j = 1;
   i++;
   printf("\n");
    }
     return 0;
}
