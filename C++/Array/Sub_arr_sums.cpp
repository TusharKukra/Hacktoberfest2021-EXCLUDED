#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int t=0;t<n;t++){
        cin>>a[t];
    }
    int curr = 0;

    for(int u=0;u<n;u++){
        curr=0;
        for(int j=u;j<n;j++){
            curr += a[j];
            cout << curr <<endl;
        }
    }
    return 0;
}