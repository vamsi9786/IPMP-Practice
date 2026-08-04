https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 
At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1])
which reduces the size of the array by 1. The player adds the chosen number to their score. 
The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and 
you should also return true. You may assume that both players are playing optimally.

Algo/Idea: Method 1: dp state return max( plyr_score-oppo_score ) i.e left=piles[i]-helper(i+1,j) and right=piles[j]-helper(i,j-1)
                      returns diff
           Method 2: dp state returns max Alice score i.e
                    left=piles[i]+min(helper(i+2,j),helper(i+1,j-1) and right=piles[j]+min(helper(i,j-2),helper(i+1,j-1))
                    why min ==> as opponent takes max one (optimally)
  
Method 1:
class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int takeleft=nums[i]-helper(i+1,j,nums,dp);
        int takeright=nums[j]-helper(i,j-1,nums,dp);
        return dp[i][j]=max(takeleft,takeright);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int res=helper(0,n-1,nums,dp);

        if(res>=0) return true;
        return false;
    }
};
  
Method 2:
class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int takeleft=nums[i]+min(helper(i+2,j,nums,dp),helper(i+1,j-1,nums,dp));
        int takeright=nums[j]+min(helper(i,j-2,nums,dp),helper(i+1,j-1,nums,dp));
        return dp[i][j]=max(takeleft,takeright);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int res=helper(0,n-1,nums,dp);

        if(sum%2==0 && res==(sum/2)) return true;

        if(res>(sum/2)) return true;
        return false;
    }
};
