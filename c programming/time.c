#include<stdio.h>
#include<stdlib.h>

typedef struct time
{
    int hour,min,sec;
}time;

time read(time *p)
{
    int i;
    printf("Enter the time in the order hour,min,sec\n");
    scanf("%d%d%d",&p->hour,&p->min,&p->sec);
    return *p;
}

void update(time *p)
{
    p->sec+=1;
    if(p->sec>59)
    {
        p->sec=0;
        p->min+=1;
        if(p->min>59)
        {
            p->min=0;
            p->hour+=1;
            if(p->hour==24)
            {
                p->hour=0;
            }
        }
    }
}

void display(time *p)
{
    printf("\ntime in the form hour:min:sec is => ");
    printf("%d : %d : %d\n",p->hour,p->min,p->sec);   
}

void add(time t1,time t2)
{
    time res;
    res.hour=t1.hour+t2.hour;
    res.min=t1.min+t2.min;
    res.sec=t1.sec+t2.sec;
    if(res.sec>59)
    {
        res.sec-=60;
        res.min+=1;
    }
    if(res.min>59)
    {
        res.min-=60;
        res.hour+=1;
    }
    if(res.hour>23)
    {
        res.hour-=24;
    }
    display(&res);

}

int main()
{
    int n,i;
   
    time *ptr,t1,t2;
    ptr=(time *)malloc(sizeof(time));
    if(ptr==NULL)
    {
        printf("Exit\n");
        exit(0);
    }
    printf("\nEnter\n1: read\n2: update\n3: display\n4: add\n");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:*ptr= read(ptr);
                    break;
            case 2:update(ptr);
                   break;
            case 3:display(ptr);
                   break;
            case 4:t1=read(ptr);
                   t2=read(ptr);
                   add(t1,t2);
                   break;
            default:printf("Invalid choice\n");
                   break;
        }
       
    } while (i>=1 && i<=4);
    free(ptr);
    return 0;
    

}