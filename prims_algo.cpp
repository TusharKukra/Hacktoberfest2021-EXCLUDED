#include<iostream>
using namespace std;

int N;
int counter=0;

int lowestCost(int *cost,bool *in_mst)
{
    int minVal=INT_MAX;
    int minIdx=-1;
    for(int i=0;i<N;i++)
    {
        counter++;
        if(cost[i]<minVal && in_mst[i]==false)
        {
            minVal=cost[i];
            minIdx=i;
        }
    }
    return minIdx;
}

void prims(int **graph)
{
    bool in_mst[N];
    int cost[N];
    int parent[N];
    for(int i=0;i<N;i++)
    {
        in_mst[i]=false;
        cost[i]=INT_MAX;
    }

    cost[0]=0;
    parent[0]=-1;
    cout<<"\nEdges in the MST and their corresponding weights"<<endl;

    for(int i=0;i<N;i++)
    {
        int vertex=lowestCost(cost,in_mst);
        in_mst[vertex]=true;
        if(parent[vertex]!=-1)
        {
            cout<<char('a'+parent[vertex])<<char('a'+vertex)<<" : "<<cost[vertex]<<endl;
        }

        for(int k=0;k<N;k++)
        {
            counter++;
            if(graph[vertex][k]>0 && graph[vertex][k]<cost[k] && in_mst[k]==false)
            {
                cost[k]=graph[vertex][k];
                parent[k]=vertex;
            }
        }
    }

    int total=0;
    for(int i=0;i<N;i++)
    {
        total+=cost[i];
    }
    cout<<"Weight of the Minimum Spanning Tree is "<<total<<endl;
}

int main()
{
    cout<<"Enter the number of vertices"<<endl;
    cin>>N;
    int **graph=new int*[N];
    for(int i=0;i<N;i++)
    {
        graph[i]=new int[N];
    }

    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>graph[i][j];
        }
    }

    prims(graph);
    cout<<endl;
    cout<<"The time complexity is O("<<counter<<")"<<endl;
    return 0;

}
