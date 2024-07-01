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

void insertByOrder(list *l,int val)
{
    int i;
    node *new =createnode(val);
    node *curr=l->head->link;
   if(curr==NULL)
   {
    new->link=new;
    l->head->link=new;
    (l->head->data)++;
    return;
   }
   if(curr->data>val)
   {
    while(curr->link!=l->head->link)
      curr=curr->link;
    curr->link=new;
    new->link=l->head->link;
    l->head->link=new;
    (l->head->data)++;
    return;
   }
    while(curr->link!=l->head->link)
    {
       if(curr->link->data<val)
        curr=curr->link;
       else
        break;
    }
    if(curr->link==l->head->link && curr->data<val) 
    { 
      curr->link=new;
      new->link=l->head->link;
    }
    else
    {   
      new->link=curr->link;
      curr->link=new;
    }
     (l->head->data)++;  
}

void deleteByPosition(list *l,int pos)
{
    int i;
    node *curr=l->head->link;
    node *temp=curr;
    if(pos<=0 || pos>l->head->data)
    {
        printf("Invalid position\n");
        return;
    }
    node *last=curr;
    if(pos==1)
    {
      while(last->link!=l->head->link)
           last=last->link;
        l->head->link=curr->link;
        last->link=l->head->link;
    }
    else
    {
      for(i=1;i<pos-1;i++)
      {
        curr=curr->link;
      }
     temp=curr->link;
     curr->link=temp->link;
    }
    free(temp);
    (l->head->data)--;
}

void searchByKey(list *l,int key)
{
    int i;
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

void deleteByKey(list *l,int key)
{
    int i=1,pos=-1;
    node *curr=l->head->link;
    do
    {
        if(curr->data==key)
        {
          printf("key found\n");
          pos=i;
          break;
        }
        i++;
        curr=curr->link;
    }while(curr!=l->head->link);
    if(pos!=-1)
    {
        deleteByPosition(l,pos);
        return;
    }
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
    int i,pos,val,key;
    list l;
    createlist(&l);

     printf("\nEnter \n1:Insert by order\n2: Delete by position\n3: Search by key\n4:delete by key\n");
     while(1)
     {
        printf("\nEnter the choice :");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("Enter the value : ");
            scanf("%d",&val);
            insertByOrder(&l,val);
            display(&l);
            break;

             case 2: printf("Enter the position : ");
            scanf("%d",&pos);
            deleteByPosition(&l,pos);
             display(&l);
            break;

             case 3: printf("Enter the key : ");
            scanf("%d",&key);
           searchByKey(&l,key);
            display(&l);
            break;

             case 4:  printf("Enter the key : ");
            scanf("%d",&key);
           deleteByKey(&l,key);
           display(&l);
            break;

            default: printf("Exit\n");
            return 0;

        }
     }
     //free(l);
     return 0;
}