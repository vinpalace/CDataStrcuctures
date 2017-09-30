#include<stdio.h>
#include<stdlib.h>

//A strcture to represent adjacency list
struct AdjListNode
{
    int dest;
    struct AdjListNode *next;

};

typedef struct AdjListNode AdjListNode;

//A structure to represent an adjacency list
struct AdjList{
    struct AdjListNode *head;

};

typedef struct AdjList AdjList;

//A structure to represent a graph. A graph is an array of adjacencylists
//size of array wil be V

struct graph
{
    int V;
    struct AdjList *array;
};

typedef struct graph graph;


//A utility function to create a new adjancey list node

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph(int V)
{
    struct graph* graph = (struct graph*)malloc(sizeof(graph));
    graph->V = V;
    //create an array of adjancency lists

    graph->array = (struct AdjList*)malloc()

    //initiliaze each adjancency list as empty by head as NULL
    int i;
    for(i = 0; i < V; i++)
        graph->array[i].head = NULL;

    return graph;


}


void addEdge(struct graph *graph, int src, int dest)
{
    //add an edge from src to dest. A new node is added to adjancenty list of src, The node isadded at beginning

    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //since graph is undirected , add an edge from 
}
