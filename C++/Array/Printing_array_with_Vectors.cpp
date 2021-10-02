#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>v){
    cout<<"size: "<<v.size()<<endl;
    for(int l=0;l<v.size();l++){
        cout<<v[l]<<" ";
    }
    cout<<endl;
}



int main(){
    vector<int>v;
    int n;
    cin>>n;
    for(int l=0;l<n;l++){
        int x;
        cin>>x;
        printVec(v);
        v.push_back(x);
    }
    printVec(v);
}