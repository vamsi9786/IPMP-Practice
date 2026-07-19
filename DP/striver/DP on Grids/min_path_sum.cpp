https://leetcode.com/problems/minimum-path-sum/description/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

class Solution {
public:
    int m,n;
    long long helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i<0 || j<0 || i>=m || j>=n) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=grid[i][j]+min(helper(i+1,j,grid,dp),helper(i,j+1,grid,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return (int)helper(0,0,grid,dp);
    }
};
