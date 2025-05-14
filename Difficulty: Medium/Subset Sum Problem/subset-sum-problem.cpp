//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(vector<int>& arr, int target, int n, vector<vector<int>>& dp)
    {
        if(target==0)return true;
        if(n==0)return false;
        if(dp[n][target]!=-1)return dp[n][target];
        if(arr[n-1]>target)return dp[n][target]=check(arr,target,n-1,dp);
        else return dp[n][target]=check(arr,target,n-1,dp) || check(arr,target-arr[n-1],n-1,dp);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<=sum;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=1;
        return check(arr,sum,n,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends