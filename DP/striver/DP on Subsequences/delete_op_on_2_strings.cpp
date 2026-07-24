https://leetcode.com/problems/delete-operation-for-two-strings/description/

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Idea: find lcs of word1 & word2 and final ans is (n1-lcs)+(n2-lcs)
  
class Solution {
public:
    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=1+helper(i-1,j-1,s1,s2,dp);

        return dp[i][j]=max(helper(i,j-1,s1,s2,dp),helper(i-1,j,s1,s2,dp));
    }

    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        int ans=helper(n1-1,n2-1,word1,word2,dp);

        return (n1-ans)+(n2-ans);
    }
};
