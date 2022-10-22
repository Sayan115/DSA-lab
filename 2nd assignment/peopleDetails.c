#include <stdio.h>
struct person
{
    char name[25];
    int age;
    char city[20];
};
int main()
{
    struct person p[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter your name: ");
        scanf("%s", &p[i].name);
        printf("Enter your age: ");
        scanf("%d", &p[i].age);
        printf("Enter your city: ");
        scanf("%s", &p[i].city);
    }
    int max = 0, t = 0;
    for (int i = 0; i < 5; i++)
    {
        if (p[i].age > max)
        {
            max = p[i].age;
            t = i;
        }
    }
    printf("Name: %s", p[t].name);
    printf("Age: %d", p[t].age);

    printf("City: %s", p[t].city);
    return 0;
}