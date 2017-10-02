#include<stdio.h>
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};
typedef struct AdjListNode ADJLISTNODE;


struct AdjListArray
{
    ADJLISTNODE *head;
};
typedef struct AdjListArray ADJLISTARRAY;

struct Graph
{
    int V;
    ADJLISTARRAY *array;
};
typedef struct Graph GRAPH;

//create graph
GRAPH* createGraph(int V)
{
    GRAPH* graph;
    graph = (GRAPH*)malloc(sizeof(GRAPH));

    graph->V = V;

    graph->array = (ADJLISTARRAY*)malloc(V * sizeof(ADJLISTARRAY));

    int i;
    for(i = 0; i < V; i++)
        graph->array[i].head = NULL;

    return graph;
}



//for adding edges
void addEdge(GRAPH* graph, int src, int dest)
{
    ADJLISTNODE *newNode;
    newNode = (ADJLISTNODE*)malloc(sizeof(ADJLISTNODE));

    newNode->dest = dest;
    newNode->next = NULL;

    newNode->next = graph->array[src].head; //for first time head is null;
    graph->array[src].head = newNode;

    //opposite now

    //ADJLISTNODE *newNode;
    newNode = (ADJLISTNODE*)malloc(sizeof(ADJLISTNODE));

    newNode->dest = src;
    newNode->next = NULL;

    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(GRAPH* graph)
{
    int vertex;

    for(vertex = 0; vertex < graph->V; vertex++)
    {
        ADJLISTNODE *crawl;

        crawl = graph->array[vertex].head;

        printf("\nList of vertex %d \t",vertex);

        while(crawl)
        {
            printf("->%d",crawl->dest);
            crawl = crawl->next;
        }

        printf("\n");
    }
}

void depthFirstSearch(GRAPH* graph)
{
    ADJLISTNODE *crawl; //first vertex
    int stack[8];
    int visitedArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int count = graph->V - 1;
    int top = 0;

    stack[top] = 0;
    printf("%d",0);
    visitedArray[0] = 1;

    while(count)
    {

        crawl = graph->array[stack[top]].head;

        while(visitedArray[crawl->dest] == 1 && crawl)
        {
            crawl = crawl->next;
        }

        top++;

        stack[top] = crawl->dest;
        printf("->%d",crawl->dest);
        visitedArray[crawl->dest] = 1;



        count--;

    }


}


void main()
{
    int V = 8;
    GRAPH *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 6);

    addEdge(graph, 1, 5);
    addEdge(graph, 1, 4);

    addEdge(graph, 2, 5);
    addEdge(graph, 2, 7);

    addEdge(graph, 3, 5);
    addEdge(graph, 3, 7);

    addEdge(graph, 4, 6);

    //printGraph(graph);
    depthFirstSearch(graph);

}
