#include <stdio.h>

void search(int f, int a[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (f == a[i])
        {
            printf("Found at:%d", i + 1);
            flag = 1;
        }
    if (flag == 0)
        printf("Not found!");
}
int main()
{
    int n, f;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter search element: ");
    scanf("%d", &f);
    search(f, a, n);
    return 0;
}