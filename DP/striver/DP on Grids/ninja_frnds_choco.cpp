

Ninja has a grid of size R x C, where each cell contains some chocolates. He has two friends: Alice and Bob, 
and wants to collect as many chocolates as possible using their help.

Alice starts at the top-left cell (0, 0)
Bob starts at the top-right cell (0, C - 1)
Both can only move to the next row, and from position (i, j), they can move to:
(i + 1, j)
(i + 1, j - 1)
(i + 1, j + 1)

Both must remain within the grid bounds. Each collects all chocolates in their current cell.
If both land on the same cell, the chocolates are only counted once.

Return the maximum number of chocolates Ninja can collect using his two friends.


class Solution {
public:

    int n,m;

    int helper(int row,int c1,int c2,
               vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp){

        if(c1<0 || c1>=m || c2<0 || c2>=m)
            return -1e9;

        if(row==n-1){

            if(c1==c2)
                return grid[row][c1];

            return grid[row][c1]+grid[row][c2];
        }

        if(dp[row][c1][c2]!=-1)
            return dp[row][c1][c2];

        int chocolates;

        if(c1==c2)
            chocolates=grid[row][c1];
        else
            chocolates=grid[row][c1]+grid[row][c2];

        int maxi=0;

        for(int d1=-1;d1<=1;d1++){

            for(int d2=-1;d2<=1;d2++){

                maxi=max(maxi,
                    helper(row+1,c1+d1,c2+d2,grid,dp));
            }
        }

        return dp[row][c1][c2]=chocolates+maxi;
    }

    int solve(int r,int c,vector<vector<int>>& grid){

        n=r;
        m=c;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m,
                vector<int>(m,-1)));

        return helper(0,0,m-1,grid,dp);
    }
};
