https://www.geeksforgeeks.org/problems/rod-cutting0840/1

Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i (1-based Index). 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: The value of n is equal to the size of price array.

class Solution {
  public:
    int helper(int i,int rem,vector<int>& price,vector<vector<int>>& dp){
        if(i<1) return 0;
        
        if(dp[i][rem]!=-1) return dp[i][rem];
        
        int take=price[i-1]+helper(rem-i,rem-i,price,dp);
        int notTake=helper(i-1,rem,price,dp);
        
        return dp[i][rem]=max(take,notTake);
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return helper(n,n,price,dp);
    }
};
