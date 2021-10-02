<<<<<<< HEAD
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)
       {

        cout<<op<<" ";
        return ;}
        string op1=op;
        string op2=op+ip[0];
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);

}

int main()
{
    string ip;
    cin>>ip;
    string op="";
    solve(ip,op);
}
=======
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)
       {

        cout<<op<<" ";
        return ;}
        string op1=op;
        string op2=op+ip[0];
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);

}

int main()
{
    string ip;
    cin>>ip;
    string op="";
    solve(ip,op);
}
>>>>>>> b34045db9330c6a252ad1e7e5cec094824d5e01d
