#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>

void printer();
struct node
{
  int num;
  struct node *ptr;
};


typedef struct node NODE;
NODE *head , *first , *temp=0,*holder;
void main()
{


  first = 0;
  int choice = 1;


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
  printer();

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
    holder = temp;
    temp = head;
    temp->ptr = holder;
  }



}

void printer()
{
temp->ptr = 0;
temp = first;
  printf("Here's after inserting a new node at place");

  while(temp!=0)
  {
    printf("%d=>",temp->num);
    temp = temp->ptr;
  }
  printf("NULL\n" );
}
