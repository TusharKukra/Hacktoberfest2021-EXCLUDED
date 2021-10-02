#include<bits/stdc++.h>
using namespace std;

void permute(string s,int l,int r,vector<string>&perm){
    if(l==r){
       cout<<s;
       perm.push_back(s);
    }

    else{
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r,perm);
            swap(s[l],s[i]);
        }
    }


}

int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<string> perm;
    permute(s,0,n-1,perm);
}