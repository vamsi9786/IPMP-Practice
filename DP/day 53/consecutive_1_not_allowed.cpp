https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

Given a positive integer n, count all possible distinct binary strings of length n such that there are no consecutive 1’s.

class Solution {
  public:
    int helper(int i,int flag,vector<vector<int>>& dp){
        if(i==0) return 1;
        
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        int ans=0;
        ans+=helper(i-1,0,dp);
        if(!flag) ans+=helper(i-1,1,dp);

        return dp[i][flag]=ans;
    }
  
    int countStrings(int n) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return helper(n,0,dp);
    }
};
