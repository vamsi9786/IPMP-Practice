https://leetcode.com/problems/longest-string-chain/description/

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
  
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of 
word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Idea: 1. sort the words based on increasing of their size
      2. similar to LIS and every word add to LIS if it is predecessor of prev (use fn calls in helper) or (calc for all i,j and pass it to helper) 

class Solution {
public:
    bool isPred(string& s1,string& s2){
        int l=s1.size(),m=s2.size();
        if(l+1!=m) return false;

        int i=0,j=0;
        bool cnt=false;
        while(i<l && j<m){
            if(s1[i]!=s2[j]){
                if(!cnt){
                    cnt=true;
                    j++;
                }
                else return false;
            }
            else{
                i++;j++;
            }
        }
        return true;
    }

    int helper(int i,int prev,vector<string>& words,vector<vector<int>>& dp,vector<vector<bool>>& flag){
        if(i<0) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0;
        if(prev==-1 || flag[prev][i]){
            take=1+helper(i-1,i,words,dp,flag);
        }
        int notTake=helper(i-1,prev,words,dp,flag);

        return dp[i][prev+1]=max(take,notTake);
    }

    static bool cmp(const string& s1,const string& s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        vector<vector<bool>> flag(n,vector<bool>(n,false));

        sort(words.begin(),words.end(),cmp);

        // flag[i][j]==> true if words[j] is preced of words[i]
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                flag[i][j]=isPred(words[j],words[i]);
            }
        }

        return helper(n-1,-1,words,dp,flag);
    }
};
