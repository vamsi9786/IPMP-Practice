https://leetcode.com/problems/coin-change/description/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

class Solution {
public:
    int helper(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(i<0 || amt<0) return INT_MAX;
        if(amt==0) return dp[i][amt]=0;

        if(dp[i][amt]!=-1) return dp[i][amt];

        int take=helper(i,amt-coins[i],coins,dp);
        int notTake=helper(i-1,amt,coins,dp);

        take=(take==INT_MAX)?INT_MAX:take+1;

        return dp[i][amt]=min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        if(amount==0) return 0;
        sort(coins.begin(),coins.end());
        int ans=helper(n-1,amount,coins,dp);
        return (ans==INT_MAX)?-1:ans;
    }
};
