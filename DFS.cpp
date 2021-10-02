/* By Aditya Raj */
// ------------- //

// Program to run DFS (Depth First Search) on a tree with n nodes and (n - 1) edges

#include <bits/stdc++.h>
using namespace std;

// adj -> is a Vector of Vector to store connected
// nodes adjacency list form

vector<vector<int>>adj;

// DFS function

void dfs(int v, int pv)
{
    cout<<v<<" ";       // Printing the visited nodes
    for(auto i:adj[v])
    {
        if(i != pv)
        {
            dfs(i, v);
        }
    }
}

// Main function

int main()
{
    int n;
    cin>>n;             // Taking input the number of nodes
    adj.resize(n + 1);
    for(int i = 0;i < n - 1;i++)
    {
        int x, y;
        cin>>x>>y;

        // Storing nodes in adjacency list form

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Calling DFS function considering the root at 1

    dfs(1, -1);
    return 0;
}