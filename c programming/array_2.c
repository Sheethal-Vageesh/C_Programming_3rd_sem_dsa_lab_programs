#include<stdio.h>
#include<stdlib.h>

void insertByPosition(int *arr,int *n,int pos,int val)
{
    int i;
    if(pos<0 || pos>*n)
    {
        printf("Invalid position\n");
        return;
    }
    for(i=*n-1;i>=pos;i--)
    {
      *(arr+i+1)=*(arr+i);
    }
    *(arr+pos)=val;
    (*n)++;
}

void deleteBykey(int *arr,int *n,int key)
{
    int i,pos=-1;
    for(i=0;i<*n;i++)
    {
        if(*(arr+i)==key)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
      printf("key not found\n");
      return;
    }
    for(i=pos+1;i<*n;i++)
    {
        *(arr+i-1)=*(arr+i);
    }
    (*n)--;
}

void searchByPosition(int *arr,int *n,int pos)
{
    int i;
    if(pos<0 || pos>=*n)
    {
        printf("Invalid position\n");
        return;
    }
   printf("%d found in given postion\n", *(arr+pos));
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
    int n,*arr,i,pos,val,key;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Exit\n");
        exit(0);
    }
     printf("\nEnter the elements of array\n ");
     for(i=0;i<n;i++)
     {
        scanf("%d",(arr+i));
     }
     printf("\nEnter \n1:Insert by position\n2: Delete by key\n3: Search by position\n4: Reverse the content\n");
     while(1)
     {
        printf("\nEnter the choice :");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("Enter the position and value : ");
            scanf("%d%d",&pos,&val);
            insertByPosition(arr,&n,pos,val);
             display(arr,&n);
            break;

             case 2: printf("Enter the key : ");
            scanf("%d",&val);
            deleteBykey(arr,&n,val);
             display(arr,&n);
            break;

             case 3: printf("Enter the position  : ");
            scanf("%d",&pos);
           searchByPosition(arr,&n,pos);
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