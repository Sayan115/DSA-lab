#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Elements \t\tNGE\n");
    for(int i=0;i<n;i++)
    {int g=-1;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i]){
                g=a[j];
                break;
            }
        }
        printf("%d \t\t\t%d\n",a[i],g);
    }
    return 0;
}