/* By Aditya Raj */
// ------------- //

/* 
   Program to find the Shortest Path between two nodes using Floyd-Warshall Algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1e9     // Defining large value to be 1e9

int main()
{
    int n;      // Number of Edges (or Paths)
    cin>>n;
    int dist[n][n];     // 2-D Matrix to store minimum distance between two nodes

    // Initialising every path to be -1

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            dist[i][j] = -1;
        }
    }

    // Distance between the same node (i.e ith to jth where i == j) is always 0

    for(int i = 0;i < n;i++)
    {
        dist[i][i] = 0;
    }

    // Taking inputs the connected nodes along with the path weigth (or distance between them)

    for(int i = 0;i < n;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        x--;y--;
        dist[x][y] = z;
        dist[y][x] = z;
    }

    // If two nodes are not connected then the defining distance between those two nodes as INF

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(dist[i][j] == -1)
            {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall function

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if(dist[i][k] == INF or dist[k][j] == INF)
                {
                    continue;
                }

                // Calculating minimum distance between connected nodes

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // taking input the nodes between which distance has to be find

    int x, y;
    cin>>x>>y;
    x--;y--;
    int ans = dist[x][y];

    /* If there is no path between the nodes that were provided
       then printing that case */
    if(ans == INF)
    {
        cout<<"No Path Exists";
        return 0;
    }

    // Printing the shortest path between the two nodes that were asked
    cout<<ans;
    return 0;
}