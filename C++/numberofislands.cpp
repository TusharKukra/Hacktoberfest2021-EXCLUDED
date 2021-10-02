#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int visited[1000][1000];
vector<pair<int,int>> v;
int dist[1000][1000];
void bfs(int m,int n)
{
	for(auto i:v)
	{
		int time = 0;
		int x = i.first;
		int y = i.second;
		dist[x][y] = 0;
		queue<pair<int,int>> q;
		q.push(make_pair(x,y));
		while(!q.empty())
		{
			int t = q.front().first;
			int u = q.front().second;
			q.pop();
			//cout<<t<<u<<" ";
			if(t+1<m and a[t+1][u]==1){a[t+1][u]=2;dist[t+1][u] = dist[t][u] + 1;q.push(make_pair(t+1,u));}
			if(u+1<m and a[t][u+1]==1){a[t][u+1]=2;dist[t][u+1] = dist[t][u] + 1;q.push(make_pair(t,u+1));}
			if(t-1>=0 and a[t-1][u]==1){a[t-1][u]=2;dist[t-1][u] = dist[t][u] + 1;q.push(make_pair(t-1,u));}
			if(u-1>=0 and a[t][u-1]==1){a[t][u-1]=2;dist[t][u-1] = dist[t][u] + 1;q.push(make_pair(t,u-1));}
			//cout<<'a'<<q.front().first<<q.front().second;
		} 
		
	}
	int fl=0;
	int maxi = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j];
			if(a[i][j]==1){fl=1;break;}
			maxi = max(maxi,dist[i][j]);
		}
	}	
	if(fl)cout<<-1;
	else cout<<maxi;
}
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(a[i][j]==2)
					{
						v.push_back(make_pair(i,j));
					}
			}
	}
	bfs(m,n);
	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		{
	// 			if(a[i][j]==1)cnt=-1;
	// 		}
	// }

	
}
