#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void push();
void pop();
void display();
struct node{
  int data;
  struct node *link;
};
typedef struct node NODE;
NODE *head=0,*temp =0,*recent=0,*newrecent;
int flag=0;

void main()
{
 int choice,option=1;
 while(option)
 {

 printf("\n1.push\n2.pop\n3.display\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: push();
 break;
 case 2:pop();
 break;
 case 3:display();
 break;
 default : printf("\n invalid choice");
 }
 printf("\nContinue\n");
 scanf("%d",&option);
 }
 }

 void push()
 {
   recent = (NODE*)malloc(sizeof(NODE));
   printf("\nenter the data to be inserted\t");
   scanf("%d",&recent->data); //mistake 2
   if(head!=0 && flag==0)
   {
     recent->link=temp;
     temp = recent; //
   }
   else if(head!=0 && flag==1)
   {
     recent->link = newrecent;
     temp = recent;
   }
   else{
     head=temp=recent;
     head->link=0;
   }
 }

  void pop()
  {
    flag = 1;
  //  NODE *newrecent;
    newrecent = recent->link;
    printf("\n %d",recent->data);
    recent = newrecent;
  }

  void display()
  {
    NODE *new;
    new = recent;
    //printf("%d",recent->data);
    while(new->link!=0)
    {
      printf("\n|%d|",new->data);
      new = new->link;
    }
    printf("\n|%d|",new->data);
  }
