#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int parent[10];

int find(int vertex){
    while(parent[vertex]){
        vertex = parent[vertex];
    }
    return vertex;
}

int uni(int u, int v){
    if(u != v){
        parent[v] = u;
        return 1;
    }
    return 0;
}

int main(){
    int n{};
    cout << "Enter the number of nodes: ";
    cin >> n;
    int input[n][n];
    cout << "\nEnter the adjacency matrix\n";
    for(int i{0}; i<n; i++){
        for(int j{0}; j<n; j++){
            cin >> input[i][j];
            if(input[i][j]==0){input[i][j]=999;}
        }
    }
    cout << endl;
    int ne{1},a{},b{},u{},v{},mincost{};
    while(ne < n){
        int min{999};
        for(int i{0}; i<n; i++){
            for(int j=0; j<n; j++){
                if(input[i][j] < min){     
                    min = input[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);                       
        v = find(v);
        if(uni(u,v)){
            cout << ne++ << " edge: " << a << "->" << b << " = " << min << endl;
            mincost += min;
        }
        input[a][b] = input[b][a] = 999;
    }
    cout << "\nMinimum cost: " << mincost << endl;;
}