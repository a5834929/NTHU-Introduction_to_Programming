#include <stdio.h>
#define MIN -1000
#define MAX 1000
int get_int(void);
int bad_limits(int begin, int end, int low, int high);
unsigned long sum_squares(int a, int b);

int main(void)
{
    int start, stop;
    unsigned long answer;

    printf("This program computes the sum of the squares of ");
    printf("integers on [-1000, 1000].\n");
    printf("Enter the limits:\nlower limit: ");

    start = get_int();
    printf("upper limit: ");
    stop = get_int();

    while(start!=0||stop!=0){
        if(bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else{
            answer = sum_squares(start, stop);
            printf("The sum of the squares of the integers ");
            printf("from %d to %d is %lu\n",start, stop, answer);
        }

        printf("Enter the limits (enter 0 for both limits to quit): \n");
        printf("lower limits: ");
        start = get_int();
        printf("upper limit: ");
        stop = get_int();
    }

    printf("Done!\n");

    return 0;
}

get_int(void)
{
    int input;
    char ch;
     while(scanf("%d", &input)!=1){
        while((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value such as 25, -12, or 3: ");

     }
     return input;
}

int bad_limits(int begin, int end, int low, int high)
{
    int not_good = 0;

    if(begin>end){
        printf("%d isn't smaller than %d.\n", begin, end);
        not_good = 1;
    }

    if(begin<low || end<low){
        printf("Values must be %d or greater.\n", low);
        not_good = 1;
    }

    if(begin>high || end>high){
        printf("Values must be %d or less.\n", high);
        not_good = 1;
    }
    return not_good;
}

unsigned long sum_squares(int a, int b)
{
    unsigned long sum;
    int i;

    for(i=a;i<=b;i++)
        sum +=i*i;

    return sum;
}
