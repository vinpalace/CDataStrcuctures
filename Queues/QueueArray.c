#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

void enqueue();
int dequeue();
void display();


struct Queue
{
    int queue_array[MAXSIZE];
    int front , rear;
};

typedef struct Queue Queue;

Queue queue;

void main()
{
    int value;
    queue.front = -1;
    queue.rear = -1;
    int choice,option=1;

    while(option)
    {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            value = dequeue();
            printf("\nThe value dequeued is %d",value);
            break;
            case 3:
            display();
            break;

        }

        printf("\nDo you want to continue enter 0 to stop?\n");
        scanf("%d",&option);

    }
}

void enqueue()
{
    int data;
    printf("\nEnter the data you want enqueue\n");
    scanf("%d",&data);

    if(queue.front==-1)
        queue.front=0;

    queue.rear = queue.rear + 1;
    queue.queue_array[queue.rear] = data;



}

int dequeue()
{
    int value;

    if(queue.front==-1 || queue.front > queue.rear)
    {
        printf("\nQueue Underflow\n");
        return -1;
    }

    else
    {
        value = queue.queue_array[queue.front];
        printf("\nThe element that got dequeued is %d",value);
        queue.front = queue.front + 1;
        return value;
    }
}

void display()
{
    if(queue.front == -1)
    {
        printf("\nIt is empty");
    }
    else
    {
    int i;
    for(i=queue.front;i<=queue.rear;i++)
    {
        printf("|%d|-",queue.queue_array[i]);
    }
    }
}
