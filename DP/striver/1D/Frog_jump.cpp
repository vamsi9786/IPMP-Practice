A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.

To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. 
The frog can jump from any step either one or two steps, provided it exists.

Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

class Solution {
public:
    int n;
    int helper(vector<int>& ht,int i,vector<int>& dp){
        if(i==0) return dp[i]=0;

        if(dp[i]!=-1) return dp[i];

        int one=helper(ht,i-1,dp)+abs(ht[i]-ht[i-1]);
        int two=(i>1)? helper(ht,i-2,dp)+abs(ht[i]-ht[i-2]) : INT_MAX;

        return dp[i]=min(one,two);
    }

    int frogJump(vector<int>& heights) {
        n=heights.size();
        vector<int> dp(n,-1);
        return helper(heights,n-1,dp);
    }
};
