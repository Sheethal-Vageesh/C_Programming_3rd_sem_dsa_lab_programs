#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *nlink;
  struct node *plink;
}node;

typedef struct list
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
    new->nlink=NULL;
    new->plink=NULL;
    return (new);
}

void createlist(list *l)
{
    l->head=createnode(0);
}

void insertByOrder(list *l,int val)
{
    node *new=createnode(val);
    node *curr=l->head->nlink;
    if(curr==NULL)
    {
        new->nlink=new;
        new->plink=new;
        l->head->nlink=new;
        (l->head->data)++;
        return;
    }
    node *last=curr->plink;
    if(curr->data>val)
    {
        new->nlink=curr;
        curr->plink=new;
        new->plink=last;
        last->nlink=new;
        l->head->nlink=new;
        (l->head->data)++;
        return;
    }
    do{
        if(curr->data>val)
          break;
        curr=curr->nlink;
      }while(curr!=l->head->nlink);
    curr->plink->nlink=new;
    new->plink=curr->plink;
    new->nlink=curr;
    curr->plink=new;
    (l->head->data)++;
}

void deleteAtFront(list *l)
{
    node *curr=l->head->nlink;
    node *last=curr->plink;
    if(curr==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(curr==last)
    {
        l->head->nlink=NULL;
    }
    else
    {
        l->head->nlink=curr->nlink;
        l->head->nlink->plink=last;
        last->nlink=l->head->nlink;
    }
    free(curr);
    (l->head->data)--;
}

void deleteAtRear(list *l)
{
    node *curr=l->head->nlink;
    node *last=curr->plink;
    if(curr==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(curr==last)
    {
        l->head->nlink=NULL;
    }
    else
    {
       last->plink->nlink=curr;
       curr->plink=last->plink;
       curr=last;
    }
    free(curr);
    (l->head->data)--;
}

void searchByKey(list *l,int key)
{
    node *curr=l->head->nlink;
    do
    {
        if(curr->data==key)
        {
          printf("key found\n");
          return;
        }
        curr=curr->nlink;
    }while(curr!=l->head->nlink);
    printf("key not found \n");
}

void display(list *l)
{
    int i;
    node *curr=l->head->nlink;
    if(curr==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("list elements are : ");
    do
    {
        printf("%d ",curr->data);
        if(curr->nlink!=l->head->nlink)
          printf(" -> ");
        curr=curr->nlink;
    }while(curr!=l->head->nlink);
    printf("\n");
}

int main()
{
    int i,pos,val,key;
    list l;
    createlist(&l);

     printf("\nEnter \n1:Insert by order\n2: Delete at front\n3:delete at rear\n4: search by key\n");
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

             case 2:deleteAtFront(&l);
             display(&l);
            break;

             case 3:deleteAtRear(&l);
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