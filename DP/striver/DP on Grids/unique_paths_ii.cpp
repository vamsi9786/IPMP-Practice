https://leetcode.com/problems/unique-paths-ii/description/

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

class Solution {
public:
    int m,n;
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        if(grid[i][j]==1) return dp[i][j]=0;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=helper(i+1,j,grid,dp)+helper(i,j+1,grid,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        if(obstacleGrid[m-1][n-1]==1) return 0;

        return helper(0,0,obstacleGrid,dp);
    }
};
