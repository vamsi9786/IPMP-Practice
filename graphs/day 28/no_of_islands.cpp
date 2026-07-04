https://leetcode.com/problems/number-of-islands/description/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Idea: Use DFS and make all next 1==>0 i.e make all 1 in same island 0 ==> after final dfs return inc ans by 1 (ans++)

class Solution {
public:
    int m;
    int n;
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(grid[i][j]=='0') return;

        grid[i][j]='0';
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
