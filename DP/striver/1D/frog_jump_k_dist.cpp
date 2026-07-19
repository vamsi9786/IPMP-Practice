A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.
  
To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. 
The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.

Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.


class Solution {
public:
    int helper(vector<int>& ht,int i,int k,vector<int>& dp){
        if(i==0) return dp[i]=0;

        if(dp[i]!=-1) return dp[i];

        int ans=INT_MAX;
        for(int idx=i-1;idx>=i-k && idx>=0;idx--){
            ans=min(ans,helper(ht,idx,k,dp)+abs(ht[i]-ht[idx]));
        }
        return dp[i]=ans;
    }

    int frogJump(vector<int>& heights, int k) {
        int n=heights.size();
        vector<int> dp(n,-1);
        return helper(heights,n-1,k,dp);
    }
};
