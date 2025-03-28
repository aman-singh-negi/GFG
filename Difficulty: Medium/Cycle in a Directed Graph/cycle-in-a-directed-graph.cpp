//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
        bool dfs(vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&stackk,int src)
        {
            visited[src]=true;
            stackk[src]=true;
            for(int i=0;i<adj[src].size();i++)
            {
                if(visited[adj[src][i]]==false)
                {
                    if(dfs(adj,visited,stackk,adj[src][i]))return true;
                }
                else if(stackk[adj[src][i]])
                {
                    return true;
                }
            }
            stackk[src]=false;
            return false;
        }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<bool>visited(n,false);
        vector<bool>stackk(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfs(adj,visited,stackk,i))return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends