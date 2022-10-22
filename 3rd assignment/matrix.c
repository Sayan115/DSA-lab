#include <stdio.h>
void count(int n, int a[n][n])
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                c++;
        }
    }

    printf("No of non-zero elements are: %d\n", c);
}

void asum(int n, int a[n][n])
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                s = s + a[i][j];
        }
    }

    printf("Sum of the elements above the leading diagonal.: %d\n", s);
}

void bsum(int n, int a[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void product(int n, int arr[n][n])
{
    int p = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                p = p * arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j == (n - 1 - i))
                p = p * arr[i][j];
printf("The product of the elements of the diagonals is %d\n",p);
}


int main()
{
    int n;
    printf("Enter the order: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {for(int j=0;j<n;j++)
        scanf("%d", &a[i][j]);
    }
    count(n,a);
    asum(n,a);
    bsum(n,a);
    product(n,a);
}