#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

struct stack
{
  int stk[MAXSIZE];
  int top;
};

typedef struct stack STACK;

STACK s;

void push();
int pop();
void display();
int isEmpty();
int isFull();

void main()
{

  s.top = -1;

  int choice , option = 1 , value;



while(option)
{
  printf("\n What do you want to do with the stack \n");
  printf("\n  1:PUSH  \n  2:POP \n  3:DISPLAY \n");
  scanf("%d",&choice);

  switch(choice)
  {
    case 1:
      push();
      break;
    case 2:
      value = pop();
      if(value == -1)
      {
        printf("\n The stack is empty to pop anymore elements\n");
      }
      else
      {
        printf("\n the value returned is %d\n",value);
      }
      break;
    case 3:
      display();
  }

  printf("\n Do you want to continue \n");
  scanf("%d",&option);
}

}

void push()
{
  if(!isFull())
  {
    int num;
    printf("\n Enter the data you want to push\n");
    scanf("%d",&num);
    s.top = s.top + 1;
    s.stk[s.top] = num;
  }
  else

  {
    printf("\n The Stack is full mate\n");
  }

}

int pop()
{
  int num;
  if(isEmpty())
  {
    printf("\n The stack is empty already\n");
    return -1;
  }
  else
  {
    num = s.stk[s.top];
    s.top = s.top - 1;
    return num;
  }
}


void display()
{
  int i=s.top;

  if(isEmpty())
  {
    printf("\n The stack empty to show anything \n");
  }
  else
  {
  while(i!=-1)
    {
      printf("|%d|\n",s.stk[i]);
      i--;
    }
  }
}


int isEmpty()
{
  if(s.top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull()
{
  if(s.top == MAXSIZE-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
