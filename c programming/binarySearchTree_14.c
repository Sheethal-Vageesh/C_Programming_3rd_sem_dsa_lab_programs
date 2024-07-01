#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node * createnode(int val)
{
  node *new=(node *)malloc(sizeof(node));
  if(new==NULL)
  {
    printf("exit\n");
    exit(0);
  }
  new->data=val;
  new->left=NULL;
  new->right=NULL;
  return new;
}

node * insertnode(node *root,int val)
{
    if(root==NULL)
    {
        node *new=createnode(val);
        return new;
    }
    if(val<root->data)
      root->left=insertnode(root->left,val);
    else 
      root->right=insertnode(root->right,val);
    return root;
}

node * deletenode(node *root,int val)
{
    node *curr=root,*q,*succ,*parent=NULL;
    while(curr!=NULL)
    {
        if(val==curr->data)
         break;
         parent=curr;
       if(val<curr->data)
          curr=curr->left;
        else 
          curr=curr->right;
    }
    if(curr==NULL)
    {
        printf("Key not found deletion not possible\n");
        return root;
    }
    if(curr->left==NULL)
      q=curr->right;
    else if(curr->right==NULL)
      q=curr->left;
    else
    {
        q=curr->right;
        succ=q;
        while(succ->left!=NULL)
          succ=succ->left;
        succ->left=curr->left;
    }
    if(parent==NULL)
      return q;
    if(parent->left==curr)
      parent->left=q;
    else  
      parent->right=q;
    free(curr);
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if(root==NULL)
      return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
      return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

node * constructBST(node *root)
{
    int i,val;
    printf("Enter the values [enter '-1' to stop]: ");
    while(1)
    {
        scanf("%d",&val);
        if(val==-1)
         break;
        root=insertnode(root,val);
    }
    return root;    
}

void searchByKey(node* root,int key)
{
  if(root==NULL)
  {
    printf("Tree is empty\n");
    return;
  }
  node *curr=root,*parent=NULL;
  while(curr!=NULL)
    {
        if(key==curr->data)
         break;
        parent=curr;
        if(key<curr->data)
          curr=curr->left;
        else 
          curr=curr->right;
    }
    if(curr==NULL)
     printf("Key not found \n");
    else if(parent !=NULL)
     printf("%d was found,and its parent is %d\n",curr->data,parent->data);
    else
     printf("%d was found,and it is root hence no parent\n",curr->data);
}

int countNodes(node *root)
{
  if(root==NULL)
   return 0;
  return 1+countNodes(root->left)+countNodes(root->right);
}

int findHeight(node *root)
{
  if(root==NULL)
   return 0;
  int lh=findHeight(root->left);
  int rh=findHeight(root->right);
  int max=(lh>rh)?lh:rh;
  return 1+max;
}

void maximum(node *root)
{
  node *curr=root,*parent=NULL;
  while(curr->right!=NULL)
    curr=curr->right;
  if(parent!=NULL)
   printf("%d is the maximum element and its parent is %d\n ",curr->data,parent->data);
  else if(curr!=NULL)
   printf("%d is the maximum element but parent not present\n",curr->data);
  else
   printf("maximum element not present\n");
}

int main()
{
  node *root=NULL;
  int choice,key,val;
  printf("\nEnter\n1: construction\n2: traversal\n3: search by Key\n4: count nodes\n5: find height\n6: find maximun key\n7: delete by key\n");
  while(1)
  {
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:root=constructBST(root);
             break;
      case 2:  printf("\ninorder : ");
               inorder(root);
               printf("\npreorder : ");
               preorder(root);
               printf("\npostorder : ");
               postorder(root);
               break;
      case 3: printf("Enter the key : ");
              scanf("%d",&key);
              searchByKey(root,key);
              break;
      case 4: val=countNodes(root);
              printf("%d nodes are present\n",val);
              break;
      case 5: val=findHeight(root);
              printf("%d is the height of tree\n",val);
              break;
      case 6:maximum(root);
              break;
      case 7: printf("Enter the key : ");
              scanf("%d",&key);
               root=deletenode(root,key);  
               break;
      default: printf("Exit from program\n");
              return 0;
              break;
                                           
    }
  }
  return 0;
}
