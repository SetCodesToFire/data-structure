#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

struct node *start = NULL;

int main(void)
{

}

struct node *create_ll(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  cout<<"\nEnter the data: ";
  cin>>num;
  new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=num;
  if(start==NULL)
  {
    new_node->next=NULL;
    start=new_node;
  }
  else
  {
    ptr=start;
    while(ptr->next!=NULL) ptr=ptr->next;
    ptr->next=new_node;
    new_node->next=NULL;
  }
  return start;
}

void *display(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
    cout<<"\n"<<ptr->data;
    ptr=ptr->next;
  }
}

struct node *insert_beg(struct node *start)
{
  struct node *new_node;
  int num;
  cout<<"\nEnter the data:";
  cin>>num;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->next=start;
  start=new_node;
  return start;
}

struct node *insert_end(struct node *start)
{
  struct node *ptr, *new_node;
  ptr=start;
  int num;
  cout<<"\nEnter the data:";
  cin>>num;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->next=NULL;
  while(ptr!=NULL) ptr=ptr->next;
  ptr->next=new_node;
  return start;
}

struct node *insert_before(struct node *start)
{
  struct node *new_node,*ptr,*preptr;
  int num,val;
  cout<<"\nEnter the data:";
  cin>>num;
  cout<<"\nEnter the value before which the data is to be inserted:";
  cin>>val;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  ptr=start;
  while(ptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  return start;
}

struct node *insert_after(struct node *start)
{
  struct node *new_node,*ptr,*preptr;
  int num,val;
  cout<<"\nEnter the data:";
  cin>>num;
  cout<<"\nEnter the value before which the data is to be inserted:";
  cin>>val;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  ptr=start;
  preptr=ptr;
  while(preptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  return start;
}

struct node *delete_beg(struct node *start)
{
  struct node *ptr;
  ptr=start;
  start=start->next;
  free(ptr);
  return ptr;
}

struct node *delete_end(struct node *start)
{
  struct node *ptr,*preptr;
  ptr=start;
  while(ptr->next!=NULL)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=NULL;
  free(ptr);
  return start;
}

struct node *delete_node(struct node *start)
{
  struct node *ptr,*preptr;
  int val;
  cout<<"\nEnter the value of the node which has to be deleted:";
  cin>>val;
  ptr=start;
  if(ptr->data==val)
  {
    start=delete_beg(start);
    return start;
  }
  while(ptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=ptr->next;
  free(ptr);
  return start;
}

struct node *delete_after(struct node *start)
{
  struct node *ptr,*preptr;
  int val;
  cout<<"\nEnter the value of the node which has to be deleted:";
  cin>>val;
  ptr=start;
  preptr=start;
  while(preptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=ptr->next;
  free(ptr);
  return start;
}

struct node *delete_list(struct node *start)
{
  struct node *ptr;
  if(start!=NULL)
  {
    ptr=start;
    while(ptr!=NULL)
    {
      cout<<"\n"<<ptr->data<<"deleting...";
      start=delete_beg(ptr);
      ptr=start;
    }
  }
  return start;
}

struct node *sorted_list(struct node *start)
{
  struct node *ptr1,*ptr2;
  int temp;
  ptr1=start;
  while(ptr->next!=NULL)
  {
    ptr2=ptr1->next;
    while(ptr2!+NULL)
    {
      if(ptr1->data > ptr2->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
      }
      ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
  }
}
