#include <stdio.h>
void build_tree(int t[], int index, int item)
{
    int ch, data;
    t[index] = item;
    printf("Do you want to enter left child of %d(1/0) ", item);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter left child: ");
        scanf("%d", &data);
        build_tree(t, 2 * index + 1, data);
    }
    printf("Do you want to enter right child of %d(1/0) ", item);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter right child: ");
        scanf("%d", &data);
        build_tree(t, 2 * index + 2, data);
    }
}
void main()
{
    int t[20];
    int item;
    for (int i = 0; i < 20; i++)
        t[i] = -1;
    printf("Enter root node: ");
    scanf("%d", &item);
    build_tree(t, 0, item);
    printf("Tree= ");
    for (int i = 0; i < 20; i++)
        if (t[i] == -1)
            printf("_ ");
        else
            printf("%d ", t[i]);
}