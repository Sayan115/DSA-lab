#include <stdio.h>
int main()
{
    int n,s;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &s);
    int f=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==s){
            f=i;
            break;
        }
    }
    if (f !=-1)
    {
        printf("The element is found at the position %d", f + 1);
    }
    else
    {
        printf("Element not found!");
    }
    return 0;
}