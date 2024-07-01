#include<stdio.h>
#include<stdlib.h>

void insertByOrder(int *arr,int *n,int val)
{
    int i;
   
    for(i=*n-1;val<*(arr+i) && i>=0;i--)
    {
      *(arr+i+1)=*(arr+i);
    }
    *(arr+i+1)=val;
    (*n)++;
}

void deleteByPosition(int *arr,int *n,int pos)
{
    int i;
    if(pos<0 || pos>=*n)
    {
        printf("Invalid position\n");
        return;
    }
    for(i=pos+1;i<*n;i++)
    {
        *(arr+i-1)=*(arr+i);
    }
    (*n)--;
}

void searchByKey(int *arr,int *n,int key)
{
    int i;
    for(i=0;i<*n;i++)
    {
        if(*(arr+i)==key)
        {
          printf("key found\n");
           return;
        }
    }
   printf("key not found \n");
}

void reverse(int *arr,int *n)
{
    int i=0,j=*n-1,temp;
    while(i<j)
    {
        temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
        i++;
        j--;
    }
}

void display(int *arr,int *n)
{
    int i;
    printf("array elements are : ");
    for(i=0;i<*n;i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int main()
{
    int n=0,*arr,i,pos,val,key,j;
    printf("Enter the size of array : ");
    scanf("%d",&j);
    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Exit\n");
        exit(0);
   }
    /* printf("\nEnter the elements of array\n ");
     for(i=0;i<n;i++)
     {
        scanf("%d",(arr+i));
     }*/
     printf("\nEnter \n1:Insert by order\n2: Delete by position\n3: Search by key\n4: Reverse the content\n");
     while(1)
     {
        printf("\nEnter the choice :");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("Enter the value : ");
            scanf("%d",&val);
            insertByOrder(arr,&n,val);
            display(arr,&n);
            break;

             case 2: printf("Enter the position : ");
            scanf("%d",&pos);
            deleteByPosition(arr,&n,pos);
             display(arr,&n);
            break;

             case 3: printf("Enter the key : ");
            scanf("%d",&key);
           searchByKey(arr,&n,key);
            display(arr,&n);
            break;

             case 4: 
           reverse(arr,&n);
           display(arr,&n);
            break;

            default: printf("Exit\n");
            return 0;

        }
     }
     free(arr);
     return 0;
}