#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
}node;

typedef struct head
{
    struct node *head;
}list;

node * createnode(int val)
{
    node *new=(node *)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("Exit\n");
        exit(0);
    }
    new->data=val;
    new->link=NULL;
    return (new);
}

void createlist(list *l)
{
    l->head=createnode(0);
}

void deleteAtFront(list *l)
{
    int i;
    node *curr=l->head->link,*last=curr;
    if(curr==NULL )
    { 
        printf("List is empty\n");
        return;
    }
    while(last->link!=l->head->link)
      last=last->link;
    node *temp=curr;
    l->head->link=temp->link;
    last->link=l->head->link;
    free(temp);
    (l->head->data)--;
}

void deleteAtRear(list *l)
{
    int i;
    node *curr=l->head->link;
    node *prev=l->head;
    if(curr==NULL )
    { 
        printf("List is empty\n");
        return;
    }
    while(curr->link!=l->head->link)
    {
      prev=curr;
      curr=curr->link;
    }
    prev->link=curr->link;
    free(curr);
    (l->head->data)--;
}

void insertByPosition(list *l,int pos,int val)
{
    int i;
    node *curr=l->head->link,*last=curr;
    node *new=createnode(val);
    if(pos<=0 || pos>l->head->data+1)
    {
        printf("Invalid position\n");
        return;
    }
    if(curr==NULL)
    {
        new->link=new;
        l->head->link=new;
        (l->head->data)++;
        return;
    }
    
    if(pos==1)
    {
      while(last->link!=l->head->link)
          last=last->link;
      new->link=curr;
      l->head->link=new;
      last->link=new;
    }
    else
    {
     for(i=1;i<pos-1;i++)
     {
      curr=curr->link;
     }
     new->link=curr->link;
     curr->link=new;
    }
    (l->head->data)++;
}


void searchByKey(list *l,int key)
{
    node *curr=l->head->link;
    do
    {
        if(curr->data==key)
        {
          printf("key found\n");
           return;
        }
        curr=curr->link;
    }while(curr!=l->head->link);
   printf("key not found \n");
}

void display(list *l)
{
    int i;
    node *curr=l->head->link;
    if(curr==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("list elements are : ");
    do
    {
        printf("%d ",curr->data);
        if(curr->link!=l->head->link)
          printf(" -> ");
        curr=curr->link;
    }while(curr!=l->head->link);
    printf("\n");
}


int main()
{
    int i,pos,val,key,n;
    list l;
    createlist(&l);
   /* printf("Enter the number of elements : ");
    scanf("%d",&n);
    l.head->data=n;
    printf("Enter the elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        insertAtRear(&l,val);
    }*/

     printf("\nEnter \n1:delete at front\n2:delete at rear \n3: insert by position\n4:search by key\n");
     while(1)
     {
        printf("\nEnter the choice :");
        scanf("%d",&i);
        switch(i)
        {
            case 1: 
            deleteAtFront(&l);
            display(&l);
            break;

             case 2: 
            deleteAtRear(&l);
             display(&l);
            break;

             case 3: printf("Enter the position and value : ");
            scanf("%d%d",&pos,&val);
           insertByPosition(&l,pos,val);
            display(&l);
            break;

             case 4:  printf("Enter the key : ");
            scanf("%d",&key);
           searchByKey(&l,key);
           display(&l);
            break;

            default: printf("Exit\n");
            return 0;

        }
     }
     //free(l);
     return 0;
}