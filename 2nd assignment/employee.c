#include <stdio.h>
#include <string.h>
struct date
{
    int day;
    int month;
    int year;
};
struct employee
{
    char name[20];
    struct date dob;
    struct date doj;
    int salary;
};

void display(struct employee e[], int n)
{
    printf("Employee details:\n\n");

    int i;

    for (i = 0; i < n; i++)
    {
        printf("Name\t\t: %s\n", e[i].name);
        printf("Date of birth\t: %02d/%02d/%d\n", e[i].dob);
        printf("Date of joining\t: %02d/%02d/%d\n", e[i].doj);
        printf("Salary\t\t: %d\n", e[i].salary);
        printf("\n");
    }
}

int comparedate(struct date d1, struct date d2)
{
    if (d1.year > d2.year)
    {
        return 1;
    }

    else if (d1.year < d2.year)
    {
        return 2;
    }

    else if (d1.year == d2.year)
    {
        if (d1.month > d2.month)
        {
            return 1;
        }

        else if (d1.month < d2.month)
        {
            return 2;
        }

        else if (d1.month == d2.month)
        {
            if (d1.day > d2.day)
            {
                return 1;
            }

            else
            {
                return 2;
            }
        }
    }
}

void sortbyname(struct employee e[], int n)
{
    struct employee temp;

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(e[i].name, e[j].name) > 0)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    display(e, n);
}

void sortbydob(struct employee e[], int n)
{
    struct employee temp;

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((comparedate(e[i].dob, e[j].dob)) == 1)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    display(e, n);
}

void sortbydoj(struct employee e[], int n)
{
    struct employee temp;

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((comparedate(e[i].doj, e[j].doj)) == 1)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    display(e, n);
}

void sortbysalary(struct employee e[], int n)
{
    struct employee temp;

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (e[i].salary < e[j].salary)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    display(e, n);
}

int main()
{
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee e[n];

    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\n\nEnter the details of employee %d:\n\n", i + 1);

        printf("Enter the name:\n");
        scanf(" %s", &e[i].name);

        printf("Enter the date of birth (dd/mm/yyyy):\n");
        scanf("%d/%d/%d", &e[i].dob.day, &e[i].dob.month, &e[i].dob.year);

        printf("Enter the date of joining (dd/mm/yyyy):\n");
        scanf("%d/%d/%d", &e[i].doj.day, &e[i].doj.month, &e[i].doj.year);

        printf("Enter the salary:\n");
        scanf("%d", &e[i].salary);
    }

    sortbyname(e, n);
    sortbydob(e, n);
    sortbydoj(e, n);
    sortbysalary(e, n);

    return 0;
}