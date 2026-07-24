https://leetcode.com/problems/longest-palindromic-subsequence/description/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Idea/Method: 1. use 2 pointers i,j if s[i]==s[j] then 1+(i-1,j-1) else max((i,j-1),(i-1,j))
             2. use lcs for 2 strings one is orig_str and other is reverse of original string rev_str

//Approach 1
class Solution {
public:
    int helper(int i,int j,string& s,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            if(i!=j) return dp[i][j]=2+helper(i+1,j-1,s,dp);
            return dp[i][j]=1+helper(i+1,j-1,s,dp);
        }
        return dp[i][j]=max(helper(i+1,j,s,dp),helper(i,j-1,s,dp));
    }

    int longestPalindromeSubseq(string s) {
        int n=s.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return helper(0,n-1,s,dp);
    }
};

//Approach 2

class Solution {
public:
    int helper(int i, int j,string &s, string &t,vector<vector<int>>& dp){

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j]=1+helper(i-1,j-1,s,t,dp);

        return dp[i][j]=max(helper(i-1,j,s,t,dp),helper(i,j-1,s,t,dp));
    }

    int longestPalindromeSubseq(string s) {

        string t=s;
        reverse(t.begin(),t.end());

        int n=s.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return helper(n-1,n-1,s,t,dp);
    }
};
