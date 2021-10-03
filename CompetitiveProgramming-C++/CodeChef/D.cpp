#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void arrange(ll A[],ll n){
    int odd=0;
    int even=1;
    while(true){
        while(even<n && A[even]%2==1)
            even+=2;
        while(odd<n && A[odd]%2==0)
            odd+=2;
        if(even<n && odd<n){
            swap(A[even],A[odd]);
        }
        else
            break;
    }
    
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll A[n];
	    for(ll i=0;i<n;i++){
	        cin>>A[i];
	    }
	    arrange(A,n);
	    ll sum=0;
	    for(ll i=0;i<n;i++){
	        sum+=(A[i]+(i+1))%2;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
