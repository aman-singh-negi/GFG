//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<vector<int>>& adj,vector<int>&visited,vector<int>&ans,int st)
    {
        visited[st]=1;
        ans.push_back(st);
        for(auto it: adj[st])
        {
            if(!visited[it])
            dfs(adj,visited,ans,it);
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>visited(n,0);
        int start=0;
        vector<int>ans;
        dfs(adj,visited,ans,start);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends