#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int m=0;m<n;m++){
        cin>>a[m];
    }

    const long long int N=100;
    bool check [N];
    for(int m=0;m<n;m++){
        check[m]= false;
    }
    for(int m=0;m<n;m++){
          if(a[m] >= 0){
            check[a[m]] = true; 
          }
    }
    int ans = -1;
    for(int j=0;j<N;j++){
        if(check[j] == false)
        {
            ans = j;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
