https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int n;
    int helper(int i,int buy,int c,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-prices[i]+helper(i+1,0,c,prices,dp),helper(i+1,1,c,prices,dp));
        }
        return dp[i][buy]=max(prices[i]+helper(i+c+1,1,c,prices,dp),helper(i+1,0,c,prices,dp));
    }

    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        //c=cooldown time
        return helper(0,1,c,prices,dp);
    }
};
