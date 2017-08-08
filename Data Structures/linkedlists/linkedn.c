#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>

void addnewnode();
void addnode();

void rebuild();
void printer();
struct node
{
  int num;
  struct node *ptr;
};


typedef struct node NODE;
NODE *head , *first , *temp=0,*holder ,*rebuilder;
void main()
{


  first = 0;
  int choice = 1;


  addnode(choice);
  addnewnode();

  printer();

}

void printer()
{
//temp->ptr = 0;
temp = first;
  printf("Here's after inserting a new node at place");

  while(temp!=0)
  {
    printf("%d=>",temp->num);
    temp = temp->ptr;
  }
  printf("NULL\n" );
}

void rebuild(int location)
{
  rebuilder = first;
  int i;
  for(i=1;i<=location-1;i++)
  {
    rebuilder = rebuilder->ptr;
  }
  rebuilder->ptr = head;

}

void addnode(int choice)
{
while(choice)
  {
  head = (NODE*)malloc(sizeof(NODE));
  printf("Enter the data \n");
  scanf("%d",&head->num);

  if(first!=0)
  {
    temp->ptr = head;
    temp = head;
  }

  else
  {
    first = temp = head;
  }
  fflush(stdin);
  printf("Do you want to continue\n" );
  scanf("%d",&choice);
}
}

void addnewnode()
{
  temp -> ptr = 0;
  temp = first;

  printf("Where do you want to insert a new node \n");

  int location,i,data;
  scanf("%d",&location);
  printf("Now enter data you want \n");

  head = (NODE*)malloc(sizeof(NODE));
  scanf("%d",&head->num);



  for(i=1;i<=location;i++)
  {
    temp = temp->ptr;
  }

  rebuild(location);

  holder = temp;
  temp = head;
  temp->ptr = holder;
  }
