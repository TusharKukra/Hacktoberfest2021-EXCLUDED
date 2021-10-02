#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    
    
    bool isPalindrome(string str, int i, int j)
    {
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int dp[][501],string str, int i ,int j)
    {
        if(i>=j)
            return 0;
        if(isPalindrome(str,i,j))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int l,r;
            if(dp[i][k]!=-1)
                l=dp[i][k];
            else
            {
                dp[i][k]=solve(dp,str, i ,k);
                l=dp[i][k];
            }
                
            if(dp[k+1][j]!=-1)
                r=dp[k+1][j];
            else{
                dp[k+1][j]=solve(dp,str,k+1,j);
                r=dp[k+1][j];
            }
            ans=min(ans, l+r+1);
                
        }
        dp[i][j]=ans;
        return ans;
            
    }
    int palindromicPartition(string str)
    {
        int ans=0;
        int n= str.length();
        int dp[501][501];
        memset(dp,-1,sizeof(dp));
        
        return solve(dp,str, 0, n-1);
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
} 


// IP:ababbbabbababa
// OP:3