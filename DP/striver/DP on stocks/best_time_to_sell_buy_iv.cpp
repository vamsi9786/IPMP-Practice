https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int n;
    int helper(int i,int buy,int cnt,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==n || cnt==k) return 0;

        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];

        if(buy){
            return dp[i][buy][cnt]=max(-prices[i]+helper(i+1,0,cnt,k,prices,dp),
                helper(i+1,1,cnt,k,prices,dp));
        }
        return dp[i][buy][cnt]=max(prices[i]+helper(i+1,1,cnt+1,k,prices,dp),helper(i+1,0,cnt,k,prices,dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k,-1)));

        return helper(0,1,0,k,prices,dp);
    }
};
