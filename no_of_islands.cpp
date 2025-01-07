//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col)
    {
        queue<pair<int, int>> Q;
        int m = grid.size(), n = grid[0].size();
        Q.push({row, col});
        vis[row][col] = 1;

        while (!Q.empty())
        {
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();

            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        Q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size(), col = grid[0].size(), no_of_islands = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    no_of_islands++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return no_of_islands;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends