//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfsTraversal(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &dfs)
    {
        visited[node] = 1;
        dfs.push_back(node);
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                dfsTraversal(i, adj, visited, dfs);
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> dfs;
        dfsTraversal(0, adj, visited, dfs);
        return dfs;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends