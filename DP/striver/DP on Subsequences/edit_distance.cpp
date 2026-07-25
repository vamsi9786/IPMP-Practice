https://leetcode.com/problems/edit-distance/description/

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
        1. Insert a character
        2. Delete a character
        2. Replace a character

Idea: Base condition: if(i<0 && j<0) return 0. if(i<0) return 1+(i,j-1). if(j<0) return 1+(i-1,j).
                or  if(i<0) return j+1. if(j<0) return i+1
      if(s1[i]==s2[j]) return (i-1,j-1)
      else return max(insert,delete,replace)
          insert ==> 1+(i-1,j)
          delete ==> 1+(i,j-1)
          replace ==> 1+(i-1,j-1)

class Solution {
public:
    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0 && j<0) return 0;
        if(i<0) return 1+helper(i,j-1,s1,s2,dp);
        if(j<0) return 1+helper(i-1,j,s1,s2,dp);

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j]=helper(i-1,j-1,s1,s2,dp);
        }

        //insert ==> 1+(i-1,j)
        //delete ==> 1+(i,j-1)
        //replace ==> 1+(i-1,j-1)

        return dp[i][j]=min(1+helper(i-1,j-1,s1,s2,dp),
            min(1+helper(i,j-1,s1,s2,dp),1+helper(i-1,j,s1,s2,dp)));
    }

    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        //if(n==0 || m==0) return (n==0)?m:n;

        return helper(n-1,m-1,word1,word2,dp);
    }
};
