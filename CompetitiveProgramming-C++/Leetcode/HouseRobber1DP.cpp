class Solution {
public:
    int rob(vector<int>& v) {
    int dp[101];
    if(v.size()==0){
         return 0;
     }
     dp[0]=v[0];
     dp[1]=max(v[0],v[1]);
     for(int i=2;i<v.size();i++){
         dp[i] = max(dp[i-1],v[i]+dp[i-2]);
     }
     return dp[v.size()-1];
    }
};