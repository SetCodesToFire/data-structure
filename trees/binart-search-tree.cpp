#include<iostream.h>
#include<conio.h>

using namespace std;

struct node{
  struct node *left;
  int data;
  struct node *right;
};

node *TREE = NULL;

 searchElement(TREE, val)
{
  if(TREE!=NULL){
    if(TREE->data == val)
    {
      return TREE;
    }
    else
    {
      if(val < TREE->data){
        return searchElement(TREE->left,val);
      }
      else{
        return searchElement(TREE->right,val);
      }
    }
  }
}

void create_tree(struct node *tree)
{
  tree=NULL;
}

//function to insert element inside the tree
struct node *insertElement(struct node *tree,int val)
{
  struct node *ptr, *nodeptr, *parentptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data=val;
  ptr->left=NULL;
  ptr->right=NULL;
  if(tree==NULL)
  {
    tree=ptr;
    tree->left=NULL;
    tree->right=NULL;
  }
  else
  {
    parentptr=NULL;
    nodeptr=tree;
    while(nodeptr!=NULL)
    {
      parentptr=nodeptr;
      if(val<nodeptr->data)
        nodeptr=nodeptr->left;
      else
        nodeptr=nodeptr->right;
    }
    if(val<parentptr->data)
      parentptr->left=ptr;
    else
      parentptr->right=ptr;
  }
  return tree;
}

//function for preorder traversal
void preorderTraversal(struct node *tree)
{
  if(tree!=NULL)
  {
    cout<<tree->data<<"\t";
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
  }
}

//function for inorder traversal
void inorderTraversal(struct node *tree)
{
  if(tree!=NULL)
  {
    inorderTraversal(tree->left);
    cout<<tree->data<<"\t";
    inorderTraversal(tree->right);
  }
}

//function for postorder traversal
void postorderTraversal(struct node *tree)
{
  if(tree!=NULL)
  {
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    cout<<tree->data<<"\t";
  }
}

//function for smallest element in the tree
struct node *findSmallestElement(struct node *tree)
{
  if(tree==NULL||tree->left==NULL)
  {
    return tree;
  }
  else
  {
    return findSmallestElement(tree->left);
  }
}

//function for largest element in the tree
struct node *findLargestElement(struct node *tree)
{
  if(tree==NULL||tree->right==NULL)
  {
    return tree;
  }
  else
  {
    return findLargestElement(tree->right);
  }
}

//function for deleting a node from the tree
struct node *deleteElement(struct node *tree,int val)
{
  struct node *cur,*parent,*suc,*psuc,*ptr;
  if(tree->left==NULL)
  {
    cout<<"\nTree is empty";
    return tree;
  }
  parent=tree;
  cur=tree->left;
  while(cur!=NULL&&val!=cur->data)
  {
    parent=cur;
    cur=(val<cur->data)?cur->left:cur->right;
  }
  if(cur==NULL)
  {
    cout<<"\nThe value to be deleted is not present in the tree";
    return tree;
  }
  if(cur->left==NULL)
    ptr=cur->right;
  else if(cur->right==NULL)
    ptr=cur->left;
  else
  {
    psuc=cur;
    cur=cur->left;
    while(suc->left!=NULL)
    {
      psuc=suc;
      suc=suc->left;
    }
    if(cur==psuc)
    {
      suc->left=cur->right;
    }
    else{
      suc->left=cur->left;
      psuc->left=suc->right;
      suc->right=cur->right;
    }
    ptr=suc;
  }
  if(parent->left==cur)
    parent->left=ptr;
  else
    parent->right=ptr;
  free(cur);
  return tree;
}

//function to count the number of nodes in a TREE
int totalNodes(struct node *tree)
{
  if(tree==NULL)
    return 0;
  else
    return (totalNodes(tree->left)+totalNodes(tree->right)+1)
}

//function to count the number of external nodes in the TREE
int totalExternalNodes(struct node *tree)
{
  if(tree==NULL)
    return 0;
  else if(tree->left==NULL&&tree->right==NULL)
    return 1;
  else
    return(totalExternalNodes(tree->left)+totalExternalNodes(tree->right));
}

//function to count the number of internal nodes in the TREE
int totalInternalNodes(struct node *tree)
{
  if(tree==NULL || tree->left==NULL&&tree->right==NULL)
    return 0;
  else
    return(totalExternalNodes(tree->left)+totalExternalNodes(tree->right)+1);
}

//function to calculate the height of the TREE
int height(struct node *tree)
{
  int leftheight,rightheight;
  if(tree==NULL)
    return 0;
  else
  {
    leftheight=height(tree->left);
    rightheight=height(tree->right);
    if(leftheight>rightheight)
      return leftheight+1;
    else
      return rightheight+1;
  }
}
