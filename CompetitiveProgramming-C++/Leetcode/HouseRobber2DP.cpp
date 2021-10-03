class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        dp[1][0]=nums[0];
        for(int i=2;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-2][0]+nums[i-1]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][1]+nums[i-1]);
        }
		
        dp[n][0]=dp[n-1][0];
        dp[n][1]=max(dp[n-1][1],dp[n-2][1]+nums[n-1]);
		
        return max(dp[n][0],dp[n][1]);
    }
};