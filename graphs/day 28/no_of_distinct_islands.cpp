https://leetcode.com/problems/number-of-distinct-islands

The key idea in Number of Distinct Islands is:
        Two islands are considered the same if they have the same shape, regardless of where they are located in the grid.

So we need a way to represent the shape of an island independent of its position.

Idea: store a set(unordered_set) for shape of islands.

Algo:  Do DFS similar to no_of_islands problem.
       Traverse every cell.
           If it is land and not visited: Start DFS.
           DFS: Record the first cell (baseRow, baseCol).
                During DFS, store (row-baseRow, col-baseCol) for every land cell.
                Store the resulting vector in a set.
           The size of the set is the answer.

  class Solution {
public:
    int n, m;

    void dfs(int r, int c,
             int br, int bc,
             vector<vector<int>>& grid,
             vector<vector<bool>>& vis,
             vector<pair<int,int>>& shape)
    {
        vis[r][c] = true;

        shape.push_back({r - br, c - bc});

        if(r > 0 && grid[r-1][c] == 1 && !vis[r-1][c]) {
            dfs(r-1, c, br, bc, grid, vis, shape);
        }
        if(c > 0 && grid[r][c-1] == 1 && !vis[r][c-1]) {
            dfs(r, c-1, br, bc, grid, vis, shape);
        }
        if(r+1 < m && grid[r+1][c] == 1 && !vis[r+1][c]) {
            dfs(r+1, c, br, bc, grid, vis, shape);
        }
        if(c+1 < n && grid[r][c+1] == 1 && !vis[r][c+1]) {
            dfs(r, c+1, br, bc, grid, vis, shape);
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    vector<pair<int,int>> shape;

                    dfs(i, j, i, j, grid, vis, shape);

                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};
