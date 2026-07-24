https://leetcode.com/problems/coin-change-ii/description/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The final answer is guaranteed to fit into a signed 32-bit integer.
  

class Solution {
public:
    int helper(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(i<0 || amt<0) return 0;

        if(amt==0) return dp[i][amt]=1;

        if(dp[i][amt]!=-1) return dp[i][amt];

        int notTake=helper(i-1,amt,coins,dp);
        int take=helper(i,amt-coins[i],coins,dp);

        return dp[i][amt]=notTake+take;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return helper(n-1,amount,coins,dp);
    }
};
