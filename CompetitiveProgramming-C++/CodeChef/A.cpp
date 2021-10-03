#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N,P,X,Y;
	    cin>>N>>P>>X>>Y;
	    int A[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    int ans=0;
	    for(int i=0;i<P;i++){
	        if(A[i]==1){
	            ans+=Y;
	        }
	        else{
	            ans+=X;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
