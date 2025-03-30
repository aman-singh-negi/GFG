//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        bool bfs(vector<vector<int>>&adj,int src)
        {
            int n=adj.size();
            queue<pair<int,int>>q;
            vector<bool>visited(n,false);
            q.push({src,-1});
            visited[src]=true;
            while(!q.empty())
            {
                pair<int,int>temp=q.front();
                q.pop();
                int r=temp.first;
                int parent=temp.second;
                for(int i=0;i<adj[r].size();i++)
                {
                    if(visited[adj[r][i]]==false)
                    {
                        q.push({adj[r][i],r});
                        visited[adj[r][i]]=true;
                    }
                    else if(parent!=adj[r][i])
                    {
                        return true;
                    }
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
        for(int i=0;i<n;i++)
        {
            if(bfs(adj,i))return true;
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