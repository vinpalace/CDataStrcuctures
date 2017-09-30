#include<stdio.h>
#include<stdlib.h>


//A structure to represent an adjanceny list node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;

};


//structure to represent adjancenylist
struct AdjList
{
    struct AdjListNode *head;

};
//A structure to rep a graph. A graph is an array of adjanceny lists
//Size of array will be V(number of verties in the graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

//Utility function that creates a new list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode;
    newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));

    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph;
    graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph->V = V;

    //create an array of adjanceny lists. Size of array will be V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    //Initilize each adjanceny list as empty by making head as NULL

    int i;

    for(i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    //Add an edge from src to dest. A new node is added to adjanceny
    //list on src. The node is added at the beginning

    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //since graph is undirected, add an edge from dest to src AdjListNode
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for(v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head",v);

        while(pCrawl)
        {
            printf("->%d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }

        printf("\n");
    }
}



//Driver program

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

    printGraph(graph);
    return 0;
}
