#include <stdio.h>

struct student
{
char name[20];
int rollno;
int marks[5];
int total;
char grade;
};

void sort(struct student s[],int n)
{ struct student t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {if(s[j].total>s[j+1].total)
                { t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                    
                }
            }
        }
    printf("Sorting: ");
   
}

void display(struct student s[],int n)
{for(int i=0;i<n;i++)
    { 
        printf("Student %d details:\n\n", i+1);
        printf("Name\t\t\t: %s\n", s[i].name);
        printf("Roll No.\t\t: %d\n", s[i].rollno);
        printf("Total marks\t\t: %d\n", s[i].total);
        printf("Grade\t\t\t: %c\n", s[i].grade);
    }
}

int main()
{   printf("Enter the no of students: ");
    int n;
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++)
    {   
        printf("Enter the name of student: ");
        scanf("%s",&s[i].name);
        printf("Enter the roll no of student: ");
        scanf("%d",&s[i].rollno);
        printf("Enter the marks of student: ");
        for(int j=0;j<5;j++){
            scanf("%d",&s[i].marks[j]);
            s[i].total+=s[i].marks[j];
        }
    }
    for(int i=0;i<n;i++)
    {   
        if(s[i].total>95)
            s[i].grade='O';
            else if(s[i].total>90)
            s[i].grade='A';
            else if(s[i].total>80)
            s[i].grade='B';
            else if(s[i].total>70)
            s[i].grade='C';
            else if(s[i].total>60)
            s[i].grade='D';
            else 
            s[i].grade='F';
    }
    sort(s,n);
    display(s,n);
}