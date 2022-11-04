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

void inorder(int t[], int pos)
{
    if (t[pos] != -1)
    {
        inorder(t, 2 * pos + 1);
        printf("%d ", t[pos]);
        inorder(t, 2 * pos + 2);
    }
}

void pre(int t[], int pos)
{
    if (t[pos] != -1)
    {
        printf("%d ", t[pos]);
        pre(t, 2 * pos + 1);
        pre(t, 2 * pos + 2);
    }
}

void post(int t[], int pos)
{
    if (t[pos] != -1)
    {
        post(t, 2 * pos + 1);
        post(t, 2 * pos + 2);
        printf("%d ", t[pos]);
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
    inorder(t, 0);
    printf("\n");
    pre(t, 0);
    printf("\n");
    post(t, 0);
}