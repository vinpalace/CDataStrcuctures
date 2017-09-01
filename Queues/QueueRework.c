#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct Queue
{
    int front , rear , size;
    int *array;
    unsigned int capacity;
};

typedef struct Queue Queue;

Queue *queue;

Queue createqueue(unsigned capacity)
{
    queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; //important for enqueue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;

}

int isFull(Queue *queue)





void main()
{

}
