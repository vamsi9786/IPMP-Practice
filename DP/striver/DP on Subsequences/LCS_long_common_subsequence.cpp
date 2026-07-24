https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. 
For example, "ABE" is a subsequence of "ABCDE".

class Solution {
  public:
    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j]=1+helper(i-1,j-1,s1,s2,dp);
        }
        
        return dp[i][j]=max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
    }
  
    int lcs(string &s1, string &s2) {
        // code here
        int l=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(l+1,vector<int>(m+1,-1));
        
        return helper(l-1,m-1,s1,s2,dp);
    }
};
