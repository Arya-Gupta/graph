//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dfs(int node, vector<vector<int>> adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                }
            }
        }

        int num_of_provinces = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                num_of_provinces++;
                dfs(i, adjList, vis);
            }
        }
        return num_of_provinces;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends