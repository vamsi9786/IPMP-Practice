

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
    
Method 2: 
Idea: Use DFS and make all next 1==>0 i.e make all 1 in same enclave/island to 0. after doing dfs for all boundary 1. 
      The remaining 1 are not reachable.
    
Method 1: Use BFS

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> que;
        vector<vector<bool>> flag(m,vector<bool> (n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) que.push({i,0});
            if(n-1!=0 && grid[i][n-1]==1) que.push({i,n-1});
        }
        for(int i=1;i<n-1;i++){
            if(grid[0][i]==1) que.push({0,i});
            if(m-1!=0 && grid[m-1][i]==1) que.push({m-1,i});
        }
        while(!que.empty()){
            auto it=que.front();
            int i=it.first;
            int j=it.second;
            que.pop();

            if(flag[i][j]) continue;
            flag[i][j]=true;

            if(i-1>=0 && !flag[i-1][j] && grid[i-1][j]==1){
                que.push({i-1,j});
            }
            if(j-1>=0 && !flag[i][j-1] && grid[i][j-1]==1){
                que.push({i,j-1});
            }
            if(i+1<m && !flag[i+1][j] && grid[i+1][j]==1){
                que.push({i+1,j});
            }
            if(j+1<n && !flag[i][j+1] && grid[i][j+1]==1){
                que.push({i,j+1});
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !flag[i][j]) res++;
            }
        }
        return res;
    }
};

Method 2: Use DFS

class Solution {
public:
    int m, n;

    void dfs(int i,int j,vector<vector<int>>& grid){

        if(i < 0 || j < 0 || i >= m || j >= n)
            return;

        if(grid[i][j] == 0)
            return;

        grid[i][j] = 0;   // mark visited

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // First row & last row
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1)
                dfs(0, j, grid);

            if(grid[m - 1][j] == 1)
                dfs(m - 1, j, grid);
        }

        // First column & last column
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1)
                dfs(i, 0, grid);

            if(grid[i][n - 1] == 1)
                dfs(i, n - 1, grid);
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
