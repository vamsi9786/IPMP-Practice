https://leetcode.com/problems/stone-game/description/?envType=daily-question&envId=2026-08-02
lc 877

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and 
each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or 
from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
  
Idea/Algo: similar to predict_winnner i.e diff b/w curr_plyr and opponent_plyr

Method 1:
class Solution {
public:
    int alice,bob;
    int helper(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int left=piles[i]-helper(i+1,j,piles,dp);
        int right=piles[j]-helper(i,j-1,piles,dp);
        return dp[i][j]=max(right,left);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return helper(0,n-1,piles,dp)>0;
    }
};

Method 2:
class Solution {
public:
    int alice,bob;
    int helper(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int takeleft=piles[i]+min(helper(i+2,j,piles,dp),helper(i+1,j-1,piles,dp));
        int takeright=piles[j]+min(helper(i,j-2,piles,dp),helper(i+1,j-1,piles,dp));
        return dp[i][j]=max(takeleft,takeright);
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return helper(0,n-1,piles,dp)>(sum/2);
    }
};
*/
