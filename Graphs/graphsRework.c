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

        printf("\nList of vertex %d\n head",V);

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

    int V;
    int choice = 1;
    int src, dest;
    printf("\nHow many nodes you want to have in your graph\n");
    scanf("%d",&V);
    GRAPH *graph = createGraph(V);
    printf("\nEnter an Edge like SRC DEST : ex- 0  1\n");
    while(choice)
    {
        printf("\nENter Edge\n");
        scanf("%d %d",&src,&dest);

        addEdge(graph, src, dest);

        printf("\nContinue?");
        scanf("%d",&choice);

    }

    printGraph(graph);
    return 0;
}
