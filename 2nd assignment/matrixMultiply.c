#include <stdio.h>

int main()
{
    int m, n, k;
    int a[m][n], b[n][k], mul[m][k];
    printf("Enter the number of row=");
    scanf("%d", &m);
    printf("Enter the number of column=");
    scanf("%d", &n);
    printf("Enter the first matrix element=\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the number of row=");
    scanf("%d", &n);
    printf("Enter the number of column=");
    scanf("%d", &k);
    
    printf("Enter the second matrix element=\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Multiplying=\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                mul[i][j] = mul[i][j] +(a[i][k] * b[k][j]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}