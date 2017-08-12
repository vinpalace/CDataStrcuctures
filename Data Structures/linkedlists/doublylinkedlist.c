#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

void create();
void print();

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};
typedef struct node NODE;

NODE *recent , *head=0, *temp;

void main()
{
  create();
  print();

}

void create()
{
  int choice = 1;

  while(choice)

  {
    recent = (NODE*)malloc(sizeof(NODE));

    printf("\n Enter the data you want to insert \n");
    scanf("%d",&recent->data);

    if(head!=0)
    {
      temp->next = recent; //node to next node
      recent->prev = temp; //back from the next node
      temp = recent; //advance temp to next node
    }
    else
    {
      temp = head = recent;
      temp->prev = NULL;

    }
    printf("\n Do you want to insert another node \n");
    scanf("%d",&choice);
  }
  temp->next = NULL;
}

void print()
{
  int count=0;
  temp = head;
  while(temp->next!=NULL)
  {
    printf("%d==>",temp->data);
    temp = temp->next;
    count++;
  }
  printf("%d==>NULL",temp->data);
  temp = temp->prev;
  printf("\n%d\n",temp->data);
  count = count + 1;
  printf("\n The number of nodes in this list are %d\n",count);
}
