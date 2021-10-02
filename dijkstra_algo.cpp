#include<iostream>
#include<iomanip>
#define INF 99999
using namespace std;

int V;

bool allChosen(bool *isChosen) {
    for(int i=0; i<V; i++) {
        if(isChosen[i] == false) return false;
    }
    return true;
}

int min(int a, int b) {
    if(a < b)
        return a;
    return b;
}

void dijkstra(int **graph, int src) {
    bool *isChosen = new bool[V];
    int *dist = new int[V];
    for(int i=0; i<V; i++) {
        isChosen[i] = false;
        dist[i] = INF;
    }

    int cv = src;
    isChosen[cv] = true;
    dist[cv] = 0;

    while(!allChosen(isChosen)) {
        for(int i=0; i<V; i++) {
            if (isChosen[i] == false && graph[cv][i] != INF) {
                dist[i] = min(dist[i], dist[cv] + graph[cv][i]);
            }
        }  
        int min_dist = INF;
        for(int i=0; i<V; i++) {
            if (isChosen[i] == false && dist[i] < min_dist) {
                min_dist = dist[i];
                cv = i;
            }
        }
        isChosen[cv] = true;
    }
    cout<<"Source"<<"   "<<"Destination"<<"   "<<"Shortest Distance"<<endl;
    for(int i=0; i<V; i++) {
        if(i == src) continue;
        cout<<"  "<<src<<"           "<<i<<"                "<<dist[i]<<endl;
    }
}

int main() {
    int **graph,src;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    graph = new int*[V];
    for(int i=0; i<V; i++)
        graph[i] = new int[V];
    cout<<"Enter the cost adjacency matrix(enter 99999 in case of no edge and 0 for self loop)"<<endl;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin>>graph[i][j];
        }
    }
    cout<<endl<<"Enter the source vertex"<<endl;
    cin>>src;
    cout<<endl;
    dijkstra(graph,src);
    return 0;
}
