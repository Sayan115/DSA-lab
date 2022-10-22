#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *HEAD, *NEW, *PTR;
    HEAD=NULL;
    NEW=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d",&NEW->data);
    NEW->next=NULL;
    HEAD=NEW;
    PTR=HEAD;
    char ch;
    printf("Do you want to add(Y/N): ");
    scanf(" %c",&ch);
    while(ch=='y'||ch=='Y')
    {
        NEW=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value: ");
        scanf("%d",&NEW->data);
        NEW->next=NULL;
        PTR->next=NEW;
        PTR=PTR->next;
        printf("Do you want to add(Y/N): ");
        scanf(" %c",&ch);
    }
    PTR=HEAD;
    while(PTR!=NULL)
    {
        printf("%d ",PTR->data);
        PTR=PTR->next;
    }

}
