/* By Aditya Raj */
// ------------- //

/* 
   Program to counted number of connected components in an
   Undirected Graph using DFS (Depth First Search)
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001     // Defining the maximum value to be 200001

// 'adj' is a Vector of Vector to store connected nodes in form of Adjacency List

vector<vector<int>>adj;

// 'visited' is a Vector to keep track of visited nodes (initially all are unvisited)

vector<int>visited(MAXN, 0);
int n, m;		// Variables for nodes and edges

// DFS function

void dfs(int v)
{
    visited[v] = 1;     // Marking the nodes as visited
    for(auto i:adj[v])
    {
        if(!visited[i])
        {
            dfs(i);     // if the connected node is not visited calling dfs function again
        }
    }
    return;
}

// Main function

int main()
{
    cin>>n>>m;          // taking input number of nodes and edges of the Graph
    adj.resize(n + 1);	// Resizing the Vector of Vector
    for(int i = 0;i < m;i++)
    {
        int x, y;
        cin>>x>>y;

        // Storing the nodes of Undirected Graph in form of Adjacency list

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
	// If node is not visited then calling DFS function

        if(visited[i])
        {
            continue;
        }
        dfs(i);
        cnt++;          // counting the number of connected components of the Undirected Graph
    }

    // Printing out the number of connected components

    cout<<cnt;
    return 0;
}