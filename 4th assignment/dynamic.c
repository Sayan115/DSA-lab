#include<stdio.h>
#include<stdlib.h>
void display(int n,int*p) 
{
    for(int i=0;i<n;i++)
        printf("%d",*(p+i));
}

void search(int s,int*p,int n)
{int t=-1;
    for(int i=0;i<n;i++)
    if(*(p+i)==s){
        t=i;
        break;
    }
    if(t!=-1)
    printf("Element found at: %d",t+1);
    else 
    printf("Element not found.");
}

void input() 
{
    int n, *p;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",p+i);
    display(n,p);
    int s;
    printf("Enter search element: ");
    scanf("%d",&s);
    search(s,p,n);
}


int main()
{
    input();
}