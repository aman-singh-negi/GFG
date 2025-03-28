//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        bool dfs(vector<vector<int>>&adj,vector<bool>&visited,int src,int parent)
        {
            visited[src]=true;
            for(int i=0;i<adj[src].size();i++)
            {
                if(!visited[adj[src][i]])
                {
                    bool a=dfs(adj,visited,adj[src][i],src);
                    if(a==true)return true;
                }
                else if(parent!=adj[src][i])
                {   
                    return true;
                }
            }
            return false;
        }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) 
    {
        // Code here
        int n=adj.size();
        vector<bool>visited(n,false);
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool a=dfs(adj,visited,i,-1);
                if(a==true)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends