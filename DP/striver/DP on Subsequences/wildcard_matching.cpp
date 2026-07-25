lc 44
https://leetcode.com/problems/wildcard-matching/description/

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

ex: abcde and ab* 
    * can consume c cd cde _(empty) 
    * e ==> consumes e and * d ==> d and * c ==> c and then b matches b and then a matches a

Algo: for ? and s[i]==p[j] return (i-1,j-1)
      for * return (i-1,j) || (i,j-1) 
            (i-1,j) ==> * consumes character 
            (i,j-1) ==> * consumes _(empty)

class Solution {
public:
    bool isAllStars(int j,string& p){
        while(j>=0){
            if(p[j]!='*') return false;
            j--;
        }
        return true;
    }

    bool helper(int i,int j,string& s,string& p,vector<vector<bool>>& dp){
        if(i<0 && j<0) return true;

        // still string exists so false
        if(j<0) return false;

        // still pattern exists and it should all contain *(stars) else false
        if(i<0) return isAllStars(j,p);

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=helper(i-1,j-1,s,p,dp);
        }

        // (i-1,j) ==> pattern stays, string moves ==> consumes char
        // (i,j-1) ==> pattern consumes "" and moves 
        if(p[j]=='*'){
            return dp[i][j]=helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
        }

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        return helper(n-1,m-1,s,p,dp);
    }
};
