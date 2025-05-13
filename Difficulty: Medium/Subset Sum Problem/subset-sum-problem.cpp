//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n= arr.size();
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<sum+1;i++)dp[0][i]=0;
        for(int i=0;i<n+1;i++)dp[i][0]=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
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