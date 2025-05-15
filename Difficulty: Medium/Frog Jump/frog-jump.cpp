//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
        int find(vector<int>&height,int idx,vector<int>&dp)
        {
            if(idx==0)return 0;
            if(idx==1)return abs(height[1]-height[0]);
            if(dp[idx]!=-1)return dp[idx];
            
            
            int oneStep=abs(height[idx]-height[idx-1])+find(height,idx-1,dp);
            int twoStep=abs(height[idx]-height[idx-2])+find(height,idx-2,dp);
            return dp[idx]=min(oneStep,twoStep);
        }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n+1,-1);
        return find(height,n-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends