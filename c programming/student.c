#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char name[50];
    int reg_no;
    int t1,t2,t3;
    float avg;
}stud;

stud *ptr;

void read(stud *p,int n)
{
    int i;
    printf("Enter the student details in the order name, register no, marks in three test out of 30\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d%d%d",p->name,&p->reg_no,&p->t1,&p->t2,&p->t3);
        p++;
    }
}

void cal_avg(stud *p,int n)
{
    int i,min;
    float avg;
    for(i=0;i<n;i++)
    {
        min=(p->t2<p->t1)?p->t2:p->t1;
        min=(min<p->t3)?min:p->t3;
        avg=(p->t1+p->t2+p->t3-min)/2.0;
        p->avg=avg;
        p++;
    }
}

void display(stud *p,int n)
{
    int i;
    cal_avg(p,n);
    printf("student details\n name\treg_no\tt1\tt2\tt3\taverage\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%f\n",p->name,p->reg_no,p->t1,p->t2,p->t3,p->avg);
        p++;
    }
}

int main()
{
    int n,i;
    printf("Enter n :");
    scanf("%d",&n);
    ptr=(stud *)malloc(n*sizeof(stud));
    if(ptr==NULL)
    {
        printf("Exit\n");
        exit(0);
    }
    printf("\nEnter\n1: read\n2: cal avg\n3: display\n");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1: read(ptr,n);
                    break;
            case 2:cal_avg(ptr,n);
                   break;
            case 3:display(ptr,n);
                   break;
            default:printf("Invalid choice\n");
                   break;
        }
       
    } while (i>=1 && i<=3);
    free(ptr);
    return 0;
    

}