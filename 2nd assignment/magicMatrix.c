
#include <stdio.h>
#include <string.h>

void square(int n)
{
    int square[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            square[i][j] = 0;
        }
    }
    int i = n - 1;
    int j = n / 2;
    int d = 1;

    while (d <= n * n)
    {
        square[i][j] = d;
        d++;
        if (i == n - 1 && j == 0)
        {
            i--;
        }
        else
        {
            i++;
            j--;
        }
        if (i == n)
        {
            i = 0;
        }
        if (j < 0)
        {
            j = n - 1;
        }
        if (square[i][j] != 0)
        {
            j++;
            i -= 2;
        }
    }

    printf("The Magic Square :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d ", square[i][j]);
        printf("\n");
    }
}

int main()
{
    int n = 0;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    if (n % 2 != 0)
    {
        square(n);
    }
    else
    {
        printf("Only odd number. ");
    }

    return 0;
}
