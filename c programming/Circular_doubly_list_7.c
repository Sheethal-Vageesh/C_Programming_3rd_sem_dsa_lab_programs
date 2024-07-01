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

void insertAtFront(list *l,int val)
{
    node *new=createnode(val);
    node *curr=l->head->nlink;
    if(curr==NULL)
    {
        l->head->nlink=new;
        new->nlink=new;
        new->plink=new;
        (l->head->data)++;
         return;
    }
    node *last=curr->plink;
    new->nlink=curr;
    curr->plink=new;
    last->nlink=new;
    new->plink=last;
    l->head->nlink=new;
    (l->head->data)++;
}

void insertAtRear(list *l,int val)
{
    node *new=createnode(val);
    node* curr=l->head->nlink,*last=curr->plink;
    if(curr==NULL)
    {
        l->head->nlink=new;
        new->nlink=new;
        new->plink=new;
        (l->head->data)++;
        return;
    }
    new->nlink=curr;
    curr->plink=new;
    last->nlink=new;
    new->plink=last;
    (l->head->data)++;
}

void deleteByPosition(list *l,int pos)
{
    int i;
    node *curr=l->head->nlink,*last=curr->plink;
    if(pos<=0 || pos>l->head->data || curr==NULL)
    {
        printf("Invalid position,deletion not possible...\n");
        return;
    }
    if(pos==1)
    {
        l->head->nlink=curr->nlink;
        last->nlink=l->head->nlink;
         l->head->nlink->plink=last;
    }
    else
    {
        for(i=1;i<pos;i++)
          curr=curr->nlink;
        curr->plink->nlink=curr->nlink;
        curr->nlink->plink=curr->plink;
    }
    free(curr);
    (l->head->data)--;
}

void searchBykey(list *l,int key)
{
    node *curr=l->head->nlink;
    do{
        if(curr->data==key)
        {
            printf("key found\n");
            return;
        }
        curr=curr->nlink;
    }while(curr!=l->head->nlink);
    printf("key not found\n");
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

    printf("\nEnter \n1:Insert at front\n2:Insert at rear\n3:delete by position\n4:search by key\n");
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
           deleteByPosition(&l,pos);
            display(&l);
            break;

             case 4:  printf("Enter the key : ");
            scanf("%d",&key);
           searchBykey(&l,key);
           display(&l);
            break;

            default: printf("Exit\n");
            return 0;

        }
     }
     //free(l);
     return 0;
}