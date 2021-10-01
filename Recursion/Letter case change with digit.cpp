#include <bits/stdc++.h>

using namespace std;
void solve(string ip,string op)

{
    string op1,op2,z;
    if(ip.size()==0)
        {cout<<op<<" ";
        return;}
    if(isdigit(ip[0]))
    {

        op1=op+ip[0];
        ip.erase(ip.begin()+0);
        solve(ip,op1);
    }
    else
    {
        z=tolower(ip[0]);
        op1=op+z;
        z=toupper(ip[0]);
        op2=op+z;
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
    }
}
int main()
{
    string ip,op;
    cin>>ip;
    op="";
    solve(ip,op);
}
