https://leetcode.com/problems/stone-game-ii/description/
Leetcode 1140

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a 
positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. 
Then, we set M = max(M, X). Initially, M = 1. The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Algo/Idea:
  Method 1: dp returns sum value as max(total-helper(i+X,newM) ==> dp return sum of all piles plyr chose
  Method 2: dp returns diff value and ===> dp return diff btw plyr and opp_plyr
            Alice + Bob = total
            Alice - Bob = diff
            Alice = (total+diff)/2

Method 1:
class Solution {
public:
    int n;
    vector<int> suff;
    int helper(int i,int m,vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(2*m>=n-i) return suff[i];

        if(dp[i][m]!=-1) return dp[i][m];

        int total=suff[i];
        int ans=0;
        
        for(int k=1;k<=2*m;k++){
            int opponent=helper(i+k,max(m,k),dp);
            ans=max(ans,total-opponent);
        }
        return dp[i][m]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suff.resize(n+1,0);

        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+piles[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return helper(0,1,dp);
    }
};

Method 2:
class Solution {
public:
    int n;

    int helper(int i,int M,vector<int>& piles,vector<vector<int>>& dp) {
        if(i==n) return 0;

        if(dp[i][M]!=INT_MIN) return dp[i][M];

        int ans=INT_MIN;
        int sum=0;

        for(int X=1;X<=2*M && i+X<=n;X++){
            sum+=piles[i+X-1];

            int next=helper(i+X,max(M,X),piles,dp);
            // current player's difference
            int diff=sum-next;

            ans=max(ans,diff);
        }

        return dp[i][M]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();

        vector<vector<int>> dp(n,vector<int>(n+1,INT_MIN));

        int total=0;
        for(int x:piles) total+=x;

        int diff=helper(0,1,piles,dp);

        // Alice = (total + Alice-Bob) / 2
        // Alice+Bob=total
        // Alice-Bob=diff
        return (total + diff)/2;
    }
};
