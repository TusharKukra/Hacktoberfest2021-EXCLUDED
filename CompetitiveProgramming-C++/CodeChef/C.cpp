#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ans=0;
	    int j=0;
	    for(int i=0;i<s.size();i++){
	        if(s[i]=='0'){
	            for(j=i;j<s.size();j++){
	                if(s[j]=='1'){
	                    break;
	                }
	            }
	            ans++;
	            i=j;
	        }
	    }
	    if(s[s.size()-1]=='0'){
	        cout<<(2*ans)-1<<"\n";
	    }
	    else{
	       cout<<(2*ans)<<endl; 
	    }
	    
	}
	return 0;
}
