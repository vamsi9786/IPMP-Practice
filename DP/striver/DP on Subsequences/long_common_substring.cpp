https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

Given two strings s1 and s2, determine the length of the longest substring that appears in both strings.

class Solution {
  public:
    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j]=1+helper(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=0;
    }
    
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,helper(i,j,s1,s2,dp));
            }
        }
        return ans;
    }
};
