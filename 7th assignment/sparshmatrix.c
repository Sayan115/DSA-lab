#include <stdio.h>
int r, c, c1, c2;

void non(int r, int c, int a[r][c])
{
    c1 = 0, c2 = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
                c2++;
            else
                c1++;
        }
}
void display(int n, int b[n][3])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
}
void sparsh(int r, int c, int a[r][c])
{
    int b[c2 + 1][3];
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = c2;
    printf("\n");
    int i = 1;
    for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++)
            if (a[j][k] != 0)
            {
                b[i][0] = j;
                b[i][1] = k;
                b[i][2] = a[j][k];
                i++;
                break;
            }

    display(c2 + 1, b);
}
int main()
{
    printf("Enter no of rows: ");
    int r, c;
    scanf("%d", &r);
    printf("Enter no of columns: ");
    scanf("%d", &c);
    int a[r][c];
    printf("Enter elements: \n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    non(r, c, a);
    sparsh(r, c, a);
    return 0;
}
