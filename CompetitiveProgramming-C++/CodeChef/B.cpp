#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll P,A,B,C,X,Y;
	    cin>>P>>A>>B>>C>>X>>Y;
	    ll ct1=(A*X)+B;
	    ll ct2=(A*Y)+C;
	    ll a=min(ct1,ct2);
	    ll final=P/a;
	    cout<<final<<"\n";
	}
	return 0;
}
