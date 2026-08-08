https://www.lintcode.com/problem/515/
lintcode 515

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.
The cost of painting each house with a certain color is different. You have to paint all the houses such that
no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, 
and so on... Find the minimum cost to paint all houses.

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int n;
    int helper(int i,int col,vector<vector<int>>& costs,vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(dp[i][col]!=-1) return dp[i][col];

        int ans=INT_MAX;
        ans=min(ans,costs[i][col]+helper(i+1,(col+1)%3,costs,dp));
        ans=min(ans,costs[i][col]+helper(i+1,(col+2)%3,costs,dp));
        return dp[i][col]=ans;
    }

    int minCost(vector<vector<int>> &costs) {
        // write your code here
        n=costs.size();

        int ans=INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        for(int i=0;i<3;i++){
            ans=min(ans,helper(0,i,costs,dp));
        }

        return ans;
    }
};
