/*
    M_coloring Problem in C

    Sample Example :
    Number Of Vertices: 4
    Number Of Edges: 5
    1 2    (x y) -> edge between node1 and node2
    1 3
    1 4
    2 3
    2 4

    Adjacency List:
                1 : 2 3 4 
                2 : 1 3 4 
                3 : 1 2   
                4 : 1 2   

Number Of Colors: 3
----------------------
NODES :  [1 2 3 4]
----------------------

Sol (1) : R G B B

Sol (2) : R B G G

Sol (3) : G R B B

Sol (4) : G B R R

Sol (5) : B R G G

Sol (6) : B G R R 

All possible solutions to color the graph with 3 colors

*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int count = 0;
// you can add more colors here
char paint[6] = {'R', 'G', 'B', 'Y', 'W', 'P'};

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
    Insert(Graph, Vj, Vi);
}

void displayList(NODE *Graph[], int N)
{
    for (int i = 1; i <= N; i++)
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
    printf("Number Of Vertices: ");
    int num_of_vertices;
    scanf("%d", &num_of_vertices);

    printf("\nNumber Of Edges: ");
    int edgeCount;
    scanf("%d", &edgeCount);

    int Vx, Vy;
    while (edgeCount--)
    {
        // printf("\nEnter Edge [ Vx - Vy ] : ");
        scanf("%d %d", &Vx, &Vy);

        createList(Graph, Vx, Vy);
    }

    printf("\nAdjacency List: \n");
    displayList(Graph, num_of_vertices);

    return num_of_vertices;
}

void displayColors(int *colors, int Vertices)
{
    count += 1;
    printf("\nSol (%d) : ", count);
    for (int i = 0; i <= Vertices; i++)
    {
        if (colors[i] != 0)
        {
            printf("%c ", paint[colors[i] - 1]);
        }
    }
    printf("\n");
}

int isValidColor(NODE *Graph[], int node, int *Colors, int color)
{
    NODE *temp = Graph[node];
    while (temp)
    {
        if (Colors[temp->data] == color)
            return 0;
        temp = temp->link;
    }
    return 1;
}

void solve(NODE *Graph[], int node, int *colors, int M, int N)
{
    if (node == N + 1)
    {
        displayColors(colors, N);
        return;
    }
    for (int i = 1; i <= M; i++)
    {
        if (isValidColor(Graph, node, colors, i))
        {
            colors[node] = i;
            solve(Graph, node + 1, colors, M, N);
            colors[node] = 0;
        }
    }
}

int main()
{
    NODE *Graph[MAX];
    initialize(Graph);

    int Vertices = getGraph(Graph);
    printf("\nNumber Of Colors: ");
    int M;
    scanf("%d", &M);

    int colors[10] = {0};
    printf("----------------------\n");
    printf("NODES :\t [");
    for (int i = 1; i <= Vertices; i++)
    {
        if (i == Vertices)
            printf("%d", i);
        else
            printf("%d ", i);
    }
    printf("]");
    printf("\n----------------------\n");
    solve(Graph, 1, colors, M, Vertices);
    if (!count)
        printf("\nNo Possible Solution");

    return 0;
}
