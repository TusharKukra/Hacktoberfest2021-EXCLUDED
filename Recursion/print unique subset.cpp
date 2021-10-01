// Rahul kumar
// Dayananda sagar college of engineering
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(string ip,string op,vector<string> &v)
{
    if(ip.length()==0)
       {
           v.push_back(op);

        //cout<<op<<" ";
        return ;}
        string op1=op;
        string op2=op+ip[0];
        ip.erase(ip.begin()+0);
        solve(ip,op1,v);
        solve(ip,op2,v);

}

int main()
{
    string ip;
    cin>>ip;
    string op;
    vector<string>v;
    unordered_set<string>s1;
    solve(ip,op,v);
    for(auto it:v)
        s1.insert(it);
    for(auto it:s1)
        cout<<it<<" ";
}
