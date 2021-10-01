#include<iostream>
using namespace std;

int size;

class Stack {
    int *a,top;
    public:
        Stack() {
            a = new int[size];
            top = -1;
        }
        void push(int num) {
            a[++top] = num;
        }
        int pop() {
            return a[top--];
        }
        bool isEmpty() {
            return (top == -1);
        }
};

bool *visited = new bool[size];
Stack s;

void topo_sort_rec(int v, int **graph) {
    if(visited[v] == true)
        return;

    for(int n=0; n<size; n++) {
        if(graph[v][n] > 0 && visited[n] == false)
            topo_sort_rec(n,graph);
    }

    visited[v] = true;
    s.push(v);  
}

void topo_sort(int **graph) {
    for(int i=0; i<size; i++)
        topo_sort_rec(i,graph);
}

int main() {
    cout<<"Enter the number of vertices"<<endl;
    cin>>size;
    int **graph;
    graph = new int*[size];
    for(int i=0; i<size; i++)
        graph[i] = new int[size];

    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++)
            cin>>graph[i][j];
    }

    for(int i=0; i<size; i++)
        visited[i] = false; 

    topo_sort(graph);

    cout<<endl<<"Vertices in topological order: ";
    while(!s.isEmpty()) 
        cout<<s.pop()<<" ";

    cout<<endl<<endl;
    return 0;
}