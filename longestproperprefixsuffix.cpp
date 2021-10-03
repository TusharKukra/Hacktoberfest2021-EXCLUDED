#include<iostream>
#include<string>
using namespace std;
int lps(string s){
		int l=s.length();
		int k=1,c=0;
		for(int i=0;i<l&&k<l;i++){
			if(s.substr(0,k)==s.substr(l-i-1,k))
				c=k;
			++k;
			}
		return c;
		
		}
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		cout<<lps(s)<<endl;		
		}
	return 0;
	}
