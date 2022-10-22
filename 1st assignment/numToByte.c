#include <stdio.h>
int main()
{
    int num;
    int number[32]={};
    printf("Enter a number: ");
    scanf("%d", &num);
    int i = 31;
    while (num!=0){
        number[i--] = num%2;
        num /= 2;
    }
    int c = 1;
    for(int j = 0;j<=24;j+=8){
        int b = 0;
        for(int k = j;k<(j+8);k++)
            b += number[k]<<(j+7-k);
            
        printf("The content of B%d is %d \n",c,b);
        c++;
    }
    return 0;
}