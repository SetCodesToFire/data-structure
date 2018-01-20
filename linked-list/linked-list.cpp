#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *start);
void display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);
struct node *sort_list(struct node *start);

int main(void)
{
  int option;
  do{
    cout<<"\n Menu:";
    cout<<"\n \t 1:Create list";
    cout<<"\n \t 2:Display list";
    cout<<"\n \t 3:Add a node at the beginning";
    cout<<"\n \t 4:Add a node at the end";
    cout<<"\n \t 5:Add a new node before a given node";
    cout<<"\n \t 6:Add a new node after a given node";
    cout<<"\n \t 7:Deleting a node from the beginning";
    cout<<"\n \t 8:Deleting a node from the end";
    cout<<"\n \t 9:Deleting a given node";
    cout<<"\n \t 10:Deleting a node after a given node";
    cout<<"\n \t 11:Deleting the entire list";
    cout<<"\n \t 12:Sort the list";
    cout<<"\n \t 13:Exit";
    cout<<"\n \t 14:Enter the choice:";
    cin>>option;
    switch(option)
    {
      case 1: start=create_ll(start);
              break;
      case 2: display(start);
              break;
      case 3: start=insert_beg(start);
              break;
      case 4: start=insert_end(start);
              break;
      case 5: start=insert_before(start);
              break;
      case 6: start=insert_after(start);
              break;
      case 7: start=delete_beg(start);
              break;
      case 8: start=delete_end(start);
              break;
      case 9: start=delete_node(start);
              break;
      case 10: start=delete_after(start);
              break;
      case 11: start=delete_list(start);
              break;
      case 12: start=sort_list(start);
              break;
    }
  }while(option!=13);
  return 0;
}

struct node *create_ll(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  cout<<"\nEnter -1 to end:::";
  cout<<"\nEnter the data: ";
  cin>>num;
  while(num!=-1)
  {
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
      cout<<"\nEnter the data:";
      cin>>num;
  }
  return start;
}

void display(struct node *start)
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
  int num;
  cout<<"\nEnter the data:";
  cin>>num;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->next=NULL;
  ptr=start;
  while(ptr->next!=NULL) ptr=ptr->next;
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
  return start;
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
  cout<<"\nEnter the value of the node,the node after this one has to be deleted:";
  cin>>val;
  ptr=start;
  preptr=ptr;
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
      cout<<"\n deleted";
      ptr=start;
    }
  }
  cout<<"\n Deleted the entire list";
  return start;
}

struct node *sort_list(struct node *start)
{
  struct node *ptr1,*ptr2;
  int temp;
  ptr1=start;
  while(ptr1->next!=NULL)
  {
    ptr2=ptr1->next;
    while(ptr2!=NULL)
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
  return start;
}
