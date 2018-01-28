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
