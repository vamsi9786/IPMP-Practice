https://leetcode.com/problems/coloring-a-border/description/

You are given an m x n integer matrix grid, and three integers row, col, and color. 
Each value in the grid represents the color of the grid square at that location.

Two squares are called adjacent if they are next to each other in any of the 4 directions.

Two squares belong to the same connected component if they have the same color and they are adjacent.

The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a 
square not in the component, or on the boundary of the grid (the first or last row or column).

You should color the border of the connected component that contains the square grid[row][col] with color.

Return the final grid.

Idea/Algo: Use BFS/DFS and find border only

Method-1: Using BFS

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> que;
        set<pair<int,int>> st;
        que.push({row,col});
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                auto [x,y]=que.front();
                que.pop();
                if(vis[x][y]) continue;
                vis[x][y]=true;
                if(x<=0 || y<=0 || x+1>=m || y+1>=n){
                    st.insert({x,y});
                }
                if(x>0){
                    if(grid[x-1][y]==grid[x][y])  que.push({x-1,y});
                    else st.insert({x,y});
                }

                if(y>0){
                    if(grid[x][y-1]==grid[x][y]) que.push({x,y-1});
                    else st.insert({x,y});
                }

                if(x+1<m){
                    if(grid[x+1][y]==grid[x][y]) que.push({x+1,y});
                    else st.insert({x,y});
                }

                if(y+1<n){
                    if(grid[x][y+1]==grid[x][y]) que.push({x,y+1});
                    else st.insert({x,y});
                }
            }
        }

        for(auto &it:st){
            grid[it.first][it.second]=color;
        }
        return grid;
    }
};

Method-2: Using DFS

class Solution {
public:
    int m, n, original;
    vector<pair<int, int>> border;
    vector<vector<bool>> vis;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = true;

        bool isBorder = false;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Outside grid → border
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                isBorder = true;
                continue;
            }

            // Neighbor has different color → border
            if (grid[nx][ny] != original) {
                isBorder = true;
                continue;
            }

            // Continue DFS
            if (!vis[nx][ny]) {
                dfs(nx, ny, grid);
            }
        }

        if (isBorder)
            border.push_back({x, y});
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row, int col, int color) {

        m = grid.size();
        n = grid[0].size();
        original = grid[row][col];

        vis.assign(m, vector<bool>(n, false));

        dfs(row, col, grid);

        for (auto &[x, y] : border)
            grid[x][y] = color;

        return grid;
    }
};
