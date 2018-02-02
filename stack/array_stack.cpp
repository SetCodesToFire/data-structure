#include<iostream>

using namespace std;

#define MAXSIZE 10
struct ArrayStack{
  int top;
  int capacity;
  int *array;
};

struct ArrayStack *CreateStack();
int isEmptyStack(struct ArrayStack *);
int isFullStack(struct ArrayStack *);
void Push(struct ArrayStack *, int data);
int Pop(struct ArrayStack *);
void DeleteStack(struct DynArrayStack *);

int main(void)
{
  
  return 0;
}

struct ArrayStack *CreateStack(){
  struct ArrayStack *S = (ArrayStack*)malloc(sizeof(struct ArrayStack *));
  if(!S)
    return NULL;
  S->capacity=MAXSIZE;
  S->top=-1;
  S->array=(int*)malloc(S->capacity*sizeof(int));
  if(!S->array)
    return NULL;
  return S;
}

int isEmptyStack(struct ArrayStack *S)
{
  return (S->top==-1);
}

int isFullStack(struct ArrayStack *S)
{
  return (S->top==S->capacity-1);
}

void Push(struct ArrayStack *S,int data)
{
  if(isFullStack(S))
    cout<<"nStack Overflow";
  else
    S->array[++S->top]=data;
}

int Pop(struct ArrayStack *S)
{
  if(isEmptyStack(S)){
    cout<<"\nStack is empty";
    return INT_MIN;;
  }
  else
    return (S->array[S->top--]);
}
