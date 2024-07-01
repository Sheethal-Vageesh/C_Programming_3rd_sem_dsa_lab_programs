#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
   int front;
   int rear;
   int *arr;
}queue;

int size;
queue *q;

void enqueueRear(int val)
{
    if(q->front==-1)
    {
        q->front=0;
        q->rear=0;
        *(q->arr+q->rear)=val;
        return;
    }
    if( q->rear==size-1)
    {
        printf("queue is full\nreallocating memory....\n");
        size++;
        q->arr=(int *)realloc(q->arr,size * sizeof(int));
        *(q->arr + ++q->rear)=val;
        return;
    }
    q->rear++;
    *(q->arr+q->rear)=val;
}

void enqueueFront(int val)
{
    if(q->front==-1)
    {
        q->front=0;
        q->rear=0;
        *(q->arr+q->rear)=val;
        return;
    }
    if(q->front==0)
    {
        printf("front insertion not possible\n");
        return;
    }
    q->front--;
    *(q->arr+q->front)=val;
}

void dequeueFront()
{
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("%d get deleted\n",*(q->arr+q->front));
    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
        return;
    }
    q->front=(q->front+1);
}

void dequeueRear()
{
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("%d get deleted\n",*(q->arr+q->rear));
    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
        return;
    }
    q->rear=(q->rear-1);
}

void display()
{
    if(q->front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i=q->front;
    while(i!=q->rear)
    {
        printf("%d ",*(q->arr+i));
        i++;
    }
    printf("%d \n",*(q->arr+i));
}

int main()
{
    int i,val;
    q=(queue *)malloc(sizeof(queue));
    printf("\nEnter the size of queue : ");
    scanf("%d",&size);
    q->arr=(int *)malloc(size*sizeof(int));
    q->front=-1;
    q->rear=-1;
    printf("\nEnter\n1: Enqueue front\n2: Enqueue rear\n3: Dequeue front\n4: Dequeue rear\n5: display\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:printf("Enter the value : ");
                   scanf("%d",&val);
                   enqueueFront(val);
                   break;
            case 2:printf("Enter the value : ");
                   scanf("%d",&val);
                   enqueueRear(val);
                   break;
            case 3:dequeueFront();
                   break;
            case 4:dequeueRear();
                   break;
            case 5:display();
                   break;
            default:printf("Exit from program\n");
                   free(q->arr);
                   free(q);
                   return 0;
                  break;
       }
    }
    return 0;
}