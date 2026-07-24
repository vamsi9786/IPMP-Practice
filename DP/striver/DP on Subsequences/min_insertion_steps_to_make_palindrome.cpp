https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.

Idea: do lcs on orig_str and rev_str and return ans=(n-lcs)

class Solution {
public:
    int helper(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=1+helper(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(helper(i,j-1,s,t,dp),helper(i-1,j,s,t,dp));
    }

    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int ans=helper(n-1,n-1,s,t,dp);

        return n-ans;
    }
};
