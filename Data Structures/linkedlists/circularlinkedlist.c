#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void create();
void print();
void addnode_front();
void createnode();
void addnode_last();
void addnode_pos();
void delete_first();
void delete_last();
void delete_position();
int counter();


struct node
{
  int data;
  struct node *link;

};

typedef struct node NODE;

NODE *head = 0 , *recent,*temp,*last=0;
int choice = 1;

void main()

{
  create();
  print();
  addnode_front();
  print();
  addnode_last();
  print();
  addnode_pos();
  print();
  delete_first();
  print();
  delete_last();
  print();
}

void create()
{
  while(choice)
  {
      createnode();
      last = recent;

      if(head!=0)
      {
        temp->link = recent;
        temp = recent;
        temp->link = head;
      }
      else
      {
        recent->link = recent;
        head = recent;
        temp = recent;
      }

      printf("Do you want to continue \n");
      scanf("%d",&choice);

  }
}



void print()
{
  printf("Entering the printer \n");
  temp = head;
  while(temp!=last)
  {
    printf("%d=>",temp->data);
    temp = temp->link;
  }
  printf("%d=>NULL\n",last->data);
  printf("Exiting the printer function \n");
}


void addnode_front()
{
  createnode(); //recent is used to point to this node
  temp = head;
  head = recent;
  head->link = temp;
  last->link = head;
  printf("Exiting front\n" );
}


void addnode_last()
{
  printf("Entering last\n" );
  createnode();

  temp = last;
  last = recent;
  temp->link = last;
  last->link = head;

  printf("Exiting Last\n" );
}

void createnode()
{
  recent =(NODE*)malloc(sizeof(NODE));
  printf("Enter the data you want to insert \n");
  scanf("%d",&recent->data);
}

int counter(int count)
{
  temp = head;

  while(temp!=last)
  {
    temp = temp->link;
    count++;
  }

  count = count+1;
  return count;

}


void addnode_pos()
{
  int count=0,location=0;
  int i;


  count = counter(count);

  printf("Enter the position you want to insert 0 for first and %d for last",count);
  scanf("%d",&location);

  if(location==0)
    addnode_front();

  else if(location==count)
    addnode_last();

  else
  {
  temp = head;
  for(i=0;i<location-2;i++)
    temp = temp -> link;

  createnode();
  recent->link = temp->link;
  temp->link = recent;
  }

}

void delete_first()
{
  temp = head;
  head = head->link;
  last->link = head;
  free(temp);
  printf("Exiting delete first\n");
}
void delete_last()
{
  int n = counter(0);

  printf("\n\n%d\n and last count is %d",last->data,n);

  temp = head;
  while(n!=2)
  {
    temp = temp->link;
    n = n - 1;
  }
  last = temp;
  last->link = head;

  temp = temp->link;

  free(temp);
  printf("Exiting delete last\n");
}
void delete_position()
{

}
