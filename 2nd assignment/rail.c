#include<stdio.h>
#include <string.h>
struct rail
{
    char name[25];
    struct time{
    int hrs;
    int min;
    int sec;
    char p[2];
}t;
}t[2];

int main()
{
     for(int i=0;i<5;i++){
        printf("\nEnter train name: ");
        scanf("%s",&t[i].name);
        printf("Enter arrival time in hrs: ");
        scanf("%d",&t[i].t.hrs);
        printf("Enter arrival time in min: ");
        scanf("%d",&t[i].t.min);
        printf("Enter arrival time in seconds: ");
        scanf("%d",&t[i].t.sec);
        printf("Enter am/pm: ");
        scanf("%s",&t[i].t.p);
     }
     int h;
     for(int i=0;i<5;i++){
      h=t[i].t.hrs;
         if(strcmp(t[i].t.p,"pm")==0)
             h=(int)(t[i].t.hrs)+12;
         printf("\n %s  will arive by %d:%d:%d",t[i].name,h,t[i].t.min,t[i].t.sec);
         h=0;
     }
}