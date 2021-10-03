//https://cses.fi/problemset/task/1197/
//https://youtu.be/kZfm68XKC58
/*Bellman ford
1)N-1 relaxations will achieve propagation if there is no negative cycle.
2)The Nth relaxation will detect if negative cycle exists or not, i.e existance of negative cycle is confirmed in this step.
3)After 1st step,further N-1 relaxations can be used to propagate -INF arising due to all -ve cycles.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> e;
    for(int i=0;i<m;i++)
    {
        ll x,y,w;
        cin >> x >> y >> w;
        e.push_back({x,y,w});
    }
    ll d[n+1]={0};
    ll s = -1;
    ll par[n+1];
    memset(par,-1,sizeof(par));
    for(int i=1;i<=(n);i++)
    {
        s = -1;
        for(auto j:e)
        {
            ll x,y,w;
            tie(x,y,w)= j;
            if((d[x]+w)<d[y])
            {
                d[y] = d[x]+w;
                s = y;
                par[y]=x;
            }
            
        }
    }
   

    if(s==-1)
    cout << "NO\n";
    else
    {
        cout << "YES\n";
        /*the s note captured may not belong to -ve cycle,so the node is traced back n-1 times,so the final s we get 		surely belongs to cycle.*/
        for(int i=1;i<=(n-1);i++)
        s=par[s];
        vector<ll> ans;
        ll temp = s;
        ans.push_back(temp);
        temp=par[s];
        while(temp!=s)
        {
            ans.push_back(temp);
            temp=par[temp];
        }
        ans.push_back(temp);

        reverse(ans.begin(),ans.end());
        for(auto i:ans)
        cout << i << " ";

    }
    return 0;
}

