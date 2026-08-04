https://leetcode.com/problems/stone-game-iii/description/?envType=daily-question&envId=2026-08-03
leetcode 1406

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and 
each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each players turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. 
The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return Alice if Alice will win, Bob if Bob will win, or Tie if they will end the game with the same score.

class Solution {
public:
    int n;
    int helper(int i,vector<int>& arr,vector<int>& dp){
        if(i>=n) return 0;

        if(dp[i]!=INT_MIN) return dp[i];

        int sum=0;
        int ans=INT_MIN;
        for(int k=0;k<3 && i+k<n;k++){
            sum+=arr[i+k];

            ans=max(ans,sum-helper(i+k+1,arr,dp));
        }
        return dp[i]=ans;
    }


    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        int sum=accumulate(stoneValue.begin(),stoneValue.end(),0);

        vector<int> dp(n,INT_MIN);
        int diff=helper(0,stoneValue,dp);

        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        return "Tie";
    }
};
