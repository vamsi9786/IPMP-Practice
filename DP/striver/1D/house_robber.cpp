https://leetcode.com/problems/house-robber/description/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>& dp){
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];
        int notTake=helper(nums,i-1,dp);

        int take=nums[i]+helper(nums,i-2,dp);
        return dp[i]=max(take,notTake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(nums,n-1,dp);
    }
};
