#include <stdio.h>
int gcd(int x, int y);

int main(void)
{
    int x, y;

    printf("Enter two integers:\n");
    scanf("%d %d", &x, &y);
    printf("(%d, %d) = %d\n", x, y, gcd(x, y));

    return 0;
}

int gcd(int x, int y)
{
    int ans;

    if(x%y!=0)
    {
        if(x>y)
            ans = gcd(y, x%y);
        else
            ans = gcd(y%x, x);
    }
    else
        ans = y;
    return ans;
}

