#include <stdio.h>
int main()
{
    int number[32] = {};
    int b = 1;    
    for(int i = 0 ; i<=24 ; i+=8){
        printf("Enter the Elements of B%d with spaces : ",b);
        for(int j = i;j<(i+8);j++)
            scanf("%d",&number[j]);
        b++;
    }
    int sum = 0;
    for(int i = 31;i>=0;i--)
        sum = sum +(number[i]<<(31-i));
    
    printf("The Required Number : %d",sum);
    return 0 ;
}