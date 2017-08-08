#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void main()
{
  struct node
  {
    int num;
    struct node *next;
  };

typedef struct node NODE;

NODE *head,*temp,*first;
int choice = 1;
first = 0;

while (choice) {

  head = (NODE*)malloc(sizeof(NODE));
  printf("Enter the Data item\n");
  scanf("%d",&head->num);

  if(first!=0)
  {
    first = head;
    first->next = temp;
    //temp->next = NULL;
    temp = first;

  }
  else
  {
    temp = first =  head;
  }
  fflush(stdin);
  printf("Do you want to contine ( Type 0 or 1 )\n");
  scanf("%d",&choice);

}


while(first!=0)
{
  printf("%d=>",first->num);
  first = first->next;
}
printf("NULL\n");

}
