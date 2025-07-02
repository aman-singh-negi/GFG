class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));

        if(n<=1)return 0;
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-1]+abs(height[i]-height[i-1]),dp[i-2]+abs(height[i]-height[i-2]));
        }
        return dp[n-1];
    }
};