#include<stdio.h>
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

typedef struct AdjListNode ADJLISTNODE;

struct AdjList
{
    struct AdjListNode *head;

};

typedef struct AdjList ADJLIST;

struct Graph
{
    int V;
    struct AdjList* array;
};

typedef struct Graph GRAPH;

void depthFirstSearch(GRAPH* graph);
int visitedCheck(int visitedArray[]);

ADJLISTNODE* newAdjListNode(int dest)
{
    ADJLISTNODE *newNode;
    newNode = (ADJLISTNODE*) malloc (sizeof(ADJLISTNODE));

    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


GRAPH* createGraph(int V)
{
    GRAPH *graph;
    graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->V = V;

    graph->array = (ADJLIST*)malloc(V * sizeof(ADJLIST));

    int i;

    //Initilize each Adjacency list as empty by making head as NULL;
    for(i = 0; i < V; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;

}



void addEdge(GRAPH *graph, int src, int dest)
{
    ADJLISTNODE *newNode  = newAdjListNode(dest);

    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //do opposite too
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void printGraph(GRAPH* graph)
{
    int v;

    for(v = 0; v < graph->V; ++v)
    {
        ADJLISTNODE *crawl;

        crawl = graph->array[v].head;

        printf("\nList of vertex %d\n head",v);

        while(crawl)
        {
            printf("->%d",crawl->dest);
            crawl = crawl->next;
        }

        printf("\n");
    }
}


int main()
{


        //create the graph
        int V = 5;
        struct Graph* graph = createGraph(V);

        addEdge(graph, 0, 1);
        addEdge(graph, 0, 4);
        addEdge(graph, 1, 2);
        addEdge(graph, 1, 3);
        addEdge(graph, 1, 4);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);

    depthFirstSearch(graph);
    return 0;
}


void depthFirstSearch(GRAPH *graph)
{
    int visitedArray[5] = {0, 0, 0, 0, 0};
    int stack[5];

    ADJLISTNODE *crawl;

    int top = 0;
    stack[top] = 0; //initial vertex
    visitedArray[0] = 1;
    int count = 4;
    int sum = 0;
    int i;

    while(count)
    {

        crawl = graph->array[stack[top]].head;

        while(visitedArray[crawl->dest] == 1 && crawl)
        {
            crawl = crawl->next;
        }

        top++;

        stack[top] = crawl->dest;
        visitedArray[crawl->dest] = 1;

        count--;


    }


    for(i = 0; i < 5; i++)
        printf("%d->",stack[i]);


        printf("\n");

    for(i = 0; i < 5; i++)
        printf("%d->",visitedArray[i]);


}


void DFS(int i)
{
    crawl = 
}
