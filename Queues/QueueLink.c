#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void enqueue();
int dequeue();
void display();

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;


NODE *front = 0 , *rear , *recent;


void main()
{
int choice = 1 ,option;

while(choice)
{
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
    scanf("%d",&option);

    switch(option)
    {
        case 1:
        enqueue();
        break;
        case 2:
        printf("\nThe value dequeued is %d",dequeue());
        break;
        case 3:
        display();
        break;
    }

    printf("\nContinue?\n");
    scanf("%d",&choice);
}

}

void enqueue()
{

    recent = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data you want to enqueue\n");
    scanf("%d",&recent->data);


        if(front==0)
        {
            rear = recent;
            front = rear;
        }
        else
        {
            rear->link = recent;
            rear = recent;
        }

}

int dequeue()
{

    NODE *temp;
    int value;
    temp = front; //for holding to free it later
    value = front->data;
    front = front->link;
    free(temp);

    return value;
}


void display()
{
    NODE *temp;
    temp = front;
    while(temp!=rear)
    {
        printf("|%d|->",temp->data);
        temp = temp -> link;
    }

    printf("|%d|->NULL",temp->data);

}
