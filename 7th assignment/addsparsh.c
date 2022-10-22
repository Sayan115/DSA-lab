#include <stdio.h>
int c1, c21, c11, c22;

void non(int r, int c, int a[r][c], int r2, int c2, int b[r][c])
{
    c1 = 0, c21 = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
                c21++;
            else
                c1++;
        }

    c11 = 0, c22 = 0;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
        {
            if (b[i][j] != 0)
                c22++;
            else
                c11++;
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
void addSparse(int s1[][3], int s2[][3], int size1, int size2, int r, int c)
{

    int res[size1 + size2 - 1][3];
    for (int i = 0; i < size1 + size2 - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = 0;
        }
    }

    int i = 1, j = 1, k = 1;
    while (i < size1 && j < size2)
    {
        if (s1[i][0] > s2[j][0])
        {
            res[k][0] = s2[j][0];
            res[k][1] = s2[j][1];
            res[k][2] = s2[j][2];
            k++;
            j++;
        }
        else if (s1[i][0] < s2[j][0])
        {
            res[k][0] = s1[i][0];
            res[k][1] = s1[i][1];
            res[k][2] = s1[i][2];
            k++;
            i++;
        }
        else
        {
            if (s1[i][1] > s2[j][1])
            {
                res[k][0] = s2[j][0];
                res[k][1] = s2[j][1];
                res[k][2] = s2[j][2];
                k++;
                j++;
            }
            else if (s1[i][1] < s2[j][1])
            {
                res[k][0] = s1[i][0];
                res[k][1] = s1[i][1];
                res[k][2] = s1[i][2];
                k++;
                i++;
            }
            else
            {
                res[k][0] = s1[i][0];
                res[k][1] = s1[i][1];
                res[k][2] = s1[i][2] + s2[j][2];
                k++;
                i++;
                j++;
            }
        }
    }
    while (i < size1)
    {
        res[k][0] = s1[i][0];
        res[k][1] = s1[i][1];
        res[k][2] = s1[i][2];
        k++;
        i++;
    }
    while (j < size2)
    {
        res[k][0] = s2[j][0];
        res[k][1] = s2[j][1];
        res[k][2] = s2[j][2];
        k++;
        j++;
    }
    int size = 0;
    for (int i = 0; i < size1 + size2 - 1; i++)
    {
        if (res[i][2] != 0)
        {
            size++;
        }
    }
    res[0][0] = r;
    res[0][1] = c;
    res[0][2] = size;
    printf("Resultant Sparse matrix:\n");
    display(size + 1, res);
}
void sparsh(int r, int c, int a[r][c], int r2, int c2, int b2[r][c])
{
    int b[c21 + 1][3];
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = c21;
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
    display(c21 + 1, b);

    int bb[c22 + 1][3];
    bb[0][0] = r2;
    bb[0][1] = c2;
    bb[0][2] = c22;
    printf("\n");
    i = 1;
    for (int j = 0; j < r2; j++)
        for (int k = 0; k < c2; k++)
            if (b2[j][k] != 0)
            {
                bb[i][0] = j;
                bb[i][1] = k;
                bb[i][2] = b2[j][k];
                i++;
                break;
            }
    display(c22 + 1, bb);
    if (r2 == r && c2 == c)
        addSparse(b, bb, c21 + 1, c22 + 1, r2, c2);
    else
        printf("Matrices are not of same dimension.");
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

    printf("Enter no of rows: ");
    int r2, c2;
    scanf("%d", &r2);
    printf("Enter no of columns: ");
    scanf("%d", &c2);
    int a2[r2][c2];
    printf("Enter elements: \n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &a2[i][j]);
    non(r, c, a, r2, c2, a2);
    sparsh(r, c, a, r2, c2, a2);
    return 0;
}
