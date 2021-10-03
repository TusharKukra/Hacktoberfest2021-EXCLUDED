#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int p=1e6+1;
    int phi[p];
    for(int i=0;i<p;i++){
        phi[i]=i;
    }
    for(int i=2;i<p;i++){
        if(phi[i]==i){
            for(int j=i;j<p;j+=i){
                phi[j]-=(phi[j]/i);
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<phi[n]<<endl;
    }
}
