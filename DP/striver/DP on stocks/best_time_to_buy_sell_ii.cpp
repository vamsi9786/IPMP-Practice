https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

Idea: if didnt bought prev then buy=1 and we can buy at idx i or pass it to idx+1 ==> max(-prices[i]+f(i,0),f(i+1,1))
      if already brought prev then buy=0 and we can sell at idx i or pass it to idx+1 ==> max(prices[i]+f(i,1),f(i+1,0))
      

class Solution {
public:
    int n;
    int helper(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(idx==n) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        if(buy){
            return dp[idx][buy]=max(-prices[idx]+helper(idx+1,0,prices,dp),helper(idx+1,1,prices,dp));
        }
        return dp[idx][buy]=max(prices[idx]+helper(idx+1,1,prices,dp),helper(idx+1,0,prices,dp));
    }

    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return helper(0,1,prices,dp);
    }
};
