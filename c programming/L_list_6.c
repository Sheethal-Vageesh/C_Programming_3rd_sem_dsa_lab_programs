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

void insertAtFront(list *l,int val)
{
    int i;
    node *new =createnode(val);
    node *curr=l->head->link;
    node *last=curr;
    if(curr==NULL )
    {
        l->head->link=new;
        new->link=new;
        (l->head->data)++;
        return;
    }
    while(last->link!=l->head->link)
      last=last->link;
      new->link=curr;
      last->link=new;
     l->head->link=new;
      (l->head->data)++;  
}

void insertAtRear(list *l,int val)
{
    int i;
    node *new =createnode(val);
    node *curr=l->head->link;
    if(curr==NULL )
    {
        l->head->link=new;
        new->link=new;
        (l->head->data)++;
        return;
    }
    while(curr->link!=l->head->link)
      curr=curr->link;

    curr->link=new;
    new->link=l->head->link;
    (l->head->data)++;  
}



void searchByPosition(list *l,int pos)
{
    int i;
    node *curr=l->head->link;
   if(pos<=0 || pos>l->head->data)
    {
        printf("Invalid position\n");
        return;
    }
     for(i=1;i<pos;i++)
      {
        curr=curr->link;
      }
     printf("%d found in given position \n",curr->data);
}

void deleteByKey(list *l,int key)
{
    int i=1,pos=-1;
    node *curr=l->head->link;
    node *temp=curr,*last=curr;
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
       curr=l->head->link;
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

     printf("\nEnter \n1:Insert at front\n2:Insert at rear\n3: Search by position\n4:delete by key\n");
     while(1)
     {
        printf("\nEnter the choice :");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("Enter the value : ");
            scanf("%d",&val);
            insertAtFront(&l,val);
            display(&l);
            break;

             case 2: printf("Enter the value : ");
            scanf("%d",&val);
            insertAtRear(&l,val);
             display(&l);
            break;

             case 3: printf("Enter the position : ");
            scanf("%d",&pos);
           searchByPosition(&l,pos);
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