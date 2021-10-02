//Generate all the balanced paranthesis.
#include <bits/stdc++.h>
using namespace std;

void solve(int open,int close,string op,vector<string>&v)
{
    if(open==0 && close==0)
    {
        v.push_back(op);
        return;
    }
    if(open!=0)
    {
        string op1 = op;
        op1.push_back('(');
        solve(open-1,close,op1,v);
    }
    if(close>open)
    {
        string op2 = op;
        op2.push_back(')');
        solve(open,close-1,op2,v);
    }
    return;
}

vector<string>valid(int n)
{
    vector<string>v;
    int open = n;
    int close = n;
    string output = "";
    solve(open,close,output,v);
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<string>ans = valid(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}