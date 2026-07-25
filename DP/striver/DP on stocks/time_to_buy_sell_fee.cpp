https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
       The transaction fee is only charged once for each stock purchase and sale.

class Solution {
public:
    int n;
    int helper(int i,int buy,int fee,vector<int>& prices,vector<vector<int>>& dp){
        if(i==n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-prices[i]+helper(i+1,0,fee,prices,dp),helper(i+1,1,fee,prices,dp));
        }
        return dp[i][buy]=max(prices[i]-fee+helper(i+1,1,fee,prices,dp),helper(i+1,0,fee,prices,dp));
    }

    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return helper(0,1,fee,prices,dp);
    }
};
