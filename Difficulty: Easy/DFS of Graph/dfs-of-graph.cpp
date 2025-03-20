//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<int>>adj,vector<int>&visited,vector<int>&ans,int idx)
    {
        ans.push_back(idx);
        visited[idx]=1;
        for(int a:adj[idx])
        {
            if(visited[a]==0)
            {
                dfs(adj,visited,ans,a);
            }
        }
    }
  public:
    // Functionto return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>visited(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(adj,visited,ans,i);
            }
        }
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