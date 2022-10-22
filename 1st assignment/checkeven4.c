#include <stdio.h>

int main()
{
 int number;
 
    printf("Enter a number to check even or odd: ");
    scanf("%d", &number);
    int copy=number;
    copy=copy>>1;
    copy=copy<<1;
    if(number ==copy)
        printf("%d is even.", number);
    else
        printf("%d is odd.", number);
    return 0;
}