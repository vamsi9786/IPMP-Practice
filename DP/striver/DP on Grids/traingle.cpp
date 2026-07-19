https://leetcode.com/problems/triangle/description/

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, 
you may move to either index i or index i + 1 on the next row.

class Solution {
public:
    int m;
    int helper(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row==m-1) return grid[row][col];

        if(dp[row][col]!=INT_MAX) return dp[row][col];

        return dp[row][col]=grid[row][col]+min(helper(row+1,col,grid,dp),helper(row+1,col+1,grid,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));

        return helper(0,0,triangle,dp);
    }
};
