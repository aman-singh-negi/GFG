//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int find(int n,vector<int>&v,vector<int>&dp)
    {
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int one=find(n-1,v,dp)+ abs(v[n]-v[n-1]);
        int two=INT_MAX;
        if(n>1)two=find(n-2,v,dp)+ abs(v[n]-v[n-2]);
        dp[n]=min(one,two);
        return dp[n];
    }
    int minCost(vector<int>& height) 
    {
        // Code here
        //Memoization
        int n=height.size();
        vector<int>dp(n,-1);
        return find(height.size()-1,height,dp);
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