// User function template for C++
class Solution {
    private:
        int findSum(vector<int>&arr,int idx,int dp[])
        {
            if(idx>=arr.size())return 0;
            if(dp[idx]!=-1)return dp[idx];
            return dp[idx]= max(arr[idx]+findSum(arr,idx+2,dp),findSum(arr,idx+1,dp));
        }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        //Memoization
        int n=arr.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return findSum(arr,0,dp);
    }
};