// DFS traversal in C
// Adjacency List creation in C

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int visited[MAX] = {0};

typedef struct Node
{
    int data;
    struct Node *link;
} NODE;

void initialize(NODE *Graph[])
{
    for (int i = 0; i < MAX; i++)
        Graph[i] = NULL;
}

NODE *newNode(int val)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = val;
    node->link = NULL;

    return node;
}

void Insert(NODE *Graph[], int V1, int V2)
{
    NODE *node1, *node2;
    node1 = newNode(V1);
    node2 = newNode(V2);

    if (Graph[V1] == NULL)
    {
        Graph[V1] = node1;
        node1->link = node2;
    }
    else
    {
        NODE *temp = Graph[V1];
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = node2;
    }
}

void createList(NODE *Graph[], int Vi, int Vj)
{
    Insert(Graph, Vi, Vj);
    // Insert(Graph, Vj, Vi);
}

void displayList(NODE *Graph[])
{
    for (int i = 1; i < MAX; i++)
    {
        if (Graph[i] == NULL)
            break;
        if (Graph[i])
        {
            NODE *temp = Graph[i];
            printf("\t\t%d : ", temp->data);
            temp = temp->link;
            while (temp)
            {
                printf("%d ", temp->data);
                temp = temp->link;
            }
        }
        printf("\n");
    }
}

int getGraph(NODE *Graph[])
{
    printf("\nNumber Of Edges: ");
    int edgeCount;
    scanf("%d", &edgeCount);
    int Edges = edgeCount;

    int Vx, Vy;
    printf("\n Edges : \n");
    while (edgeCount--)
    {
        scanf("%d %d", &Vx, &Vy);
        createList(Graph, Vx, Vy);
    }

    printf("\nAdjacency List: \n");
    displayList(Graph);

    return Edges;
}

void DFS(NODE *Graph[], int index)
{
    NODE *temp = Graph[index];
    visited[index] = 1;
    printf(" V%d", index);
    while (temp)
    {
        index = temp->data;

        if (!visited[index])
            DFS(Graph, index);
        temp = temp->link;
    }
}

int main()
{
    NODE *Graph[MAX];
    initialize(Graph);

    int edges = getGraph(Graph);

    printf("\nDFS: ");
    DFS(Graph, 1);

    return 0;
}
