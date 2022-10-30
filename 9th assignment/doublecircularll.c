#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insertNode(struct node *HEAD)
{
    int pos, value;
    printf("Enter data and position: ");
    scanf("%d %d", &value, &pos);
    struct node *NEW = (struct node *)malloc(sizeof(struct node));
    NEW->data = value;
    if (pos == 1)
    {
        NEW->next = HEAD;
        struct node *ptr = HEAD;
        while (ptr->next != HEAD && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NEW;
        NEW->prev = ptr;
        return NEW;
    }
    struct node *ptr = HEAD;
    int count = 1;
    while (ptr->next != HEAD && count < pos - 1)
    {
        ptr = ptr->next;
        count++;
    }
    struct node *temp = ptr->next;
    ptr->next = NEW;
    NEW->next = temp;
    NEW->prev = ptr;
    return HEAD;
}

struct node *create(struct node *prev)
{
    struct node *NEW = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &NEW->data);
    NEW->next = NULL;
    NEW->prev = prev;
    return NEW;
}
void printLL(struct node *HEAD)
{
    if (HEAD == NULL)
    {
        return;
    }
    struct node *ptr = HEAD;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != HEAD && ptr != NULL);
    printf("\n");
    ptr = HEAD;
	while (ptr->next != HEAD)
	{
		ptr = ptr->next;
	}
	while (ptr != HEAD)
	{
		printf("%d ", ptr->data);
		ptr = ptr->prev;
	}
	printf("%d ", ptr->data);

}

int main()
{
    char choice;
    struct node *HEAD, *NEW;
    HEAD = NULL;
    NEW = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &NEW->data);
    NEW->next = NEW;
    NEW->prev = NEW;
    HEAD = NEW;
    printf("Do you want to add another node(Y/N)\n");
    scanf(" %c", &choice);
    while (choice == 'Y' || choice == 'y')
    {
        NEW->next = create(NEW);
        NEW = NEW->next;
        printf("Do you want to add another node(Y/N)\n");
        scanf(" %c", &choice);
    }
    if (NEW != HEAD)
    {
        NEW->next = HEAD;
        HEAD->prev = NEW;
    }
    int ch = 1;
    while (ch == 1 || ch == 2 || ch == 3)
    {
        printf("Enter 1 to insert node\n2 to display: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            HEAD = insertNode(HEAD);
            printLL(HEAD);
        }
        else if (ch == 2)
        {
            printLL(HEAD);
        }
        else
        {
            break;
        }
    }
}