https://leetcode.com/problems/shortest-common-supersequence/description/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Idea: Keep the common characters only once (the LCS), and include all other characters from both strings.

Algo: We need the shortest string that contains both as subsequences.  
      Step 1: Find the LCS
              Why is LCS important? Because these characters are common to both strings.
              Instead of writing them twice, we write them once.
      Step 2: Step 2: Build the DP table. This is the normal LCS table.
      Step 3: Backtrack. Start from i=n j=m
              Case 1: Characters Match. If str1[i-1] == str2[j-1] then Both strings need this character.
                      so add it once ==> ans += 'a' and move diagonally i-- , j--.
              Case 2: Characters Dont Match. They are different. One of them is not in the LCS.
                      we check ==> dp[i-1][j] and dp[i][j-1]
                      if dp[i-1][j] > dp[i][j-1] ==> we move upward
                        i.e Ignoring current character of str1 keeps a longer LCS.
                      else: Move left. Current character of str2 is not shared.

class Solution {
public:
    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=1+helper(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(helper(i,j-1,s1,s2,dp),helper(i-1,j,s1,s2,dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();

        string temp;
        int idx1,idx2;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        helper(n-1,m-1,str1,str2,dp);

        int i=n-1,j=m-1;
        string ans;

        while(i>=0 && j>=0){
            if(str1[i]==str2[j]){
                ans+=str1[i];
                i--;
                j--;
            }
            else if(dp[i][j+1]>dp[i+1][j]){
                ans+=str1[i];
                i--;
            }
            else{
                ans+=str2[j];
                j--;
            }
        }

        while(i>=0){
            ans+=str1[i];
            i--;
        }
        while(j>=0){
            ans+=str2[j];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
