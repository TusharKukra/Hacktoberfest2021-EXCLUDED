#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter Number:";
    int x,temp;
    cin>>x;
    int prev=0, curr=0, next=1;

    for(int i=0;i<x;i++)
    {
        prev=curr;

        curr=next;

        next=prev+curr;

        cout<<prev<<" ";
    }
    
}
