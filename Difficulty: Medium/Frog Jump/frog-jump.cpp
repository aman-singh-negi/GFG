class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();

        if(n<=1)return 0;
        int dp0=0;
        int dp1=abs(height[1]-height[0]);
        for(int i=2;i<n;i++)
        {
            int dp2=min(dp1+abs(height[i]-height[i-1]),dp0+abs(height[i]-height[i-2]));
            dp0=dp1;
            dp1=dp2;
        }
        return dp1;
    }
};