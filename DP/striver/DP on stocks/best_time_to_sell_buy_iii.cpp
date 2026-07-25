https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Idea: As there exists three variables changing states so we need to maintain 3D DP Table

class Solution {
public:
    int n;
    int helper(int i,int buy,int cnt,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==n || cnt==2) return 0;

        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];

        if(buy){
            return dp[i][buy][cnt]=max(-prices[i]+helper(i+1,0,cnt,prices,dp),helper(i+1,1,cnt,prices,dp));
        }
        return dp[i][buy][cnt]=max(prices[i]+helper(i+1,1,cnt+1,prices,dp),helper(i+1,0,cnt,prices,dp));
    }

    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        return helper(0,1,0,prices,dp);
    }
};
