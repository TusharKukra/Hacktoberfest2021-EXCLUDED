#include<bits/stdc++.h>
using namespace std;

bool issafe(int i,int j,vector<vector<int>> &maze,int n){
    if(i<=n&&j<=n&&maze[i][j]==1) return true;
    return false;
}

bool solve(vector<vector<int>> &maze, int x,int y,int n){
    if(x==n&&y==n) {
        cout<<"Yes";
        return true;
    }

    if(issafe(x,y,maze,n)){
        
        if(solve(maze,x+1,y,n)) return true;
        else if(solve(maze,x,y+1,n)) return true;

    }
    return false;
}



int main(){
    int n;
    cin>>n;
    vector<int> curr(n);
    vector<vector<int>> maze;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>curr[j];
        }
        maze.push_back(curr);
        curr.clear();
    }
    
    solve(maze,0,0,n-1);
}