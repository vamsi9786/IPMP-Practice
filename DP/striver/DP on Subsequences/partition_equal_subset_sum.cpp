https://leetcode.com/problems/partition-equal-subset-sum/description/

Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.

Idea: 1. Check a subset/subsequence exists with sum ===> arr_sum/2;
      2. Maintain 2 variables sum_so_far and remain_sum ===> if at any time they are equal return true

Idea 1:
class Solution {
public:

    bool helper(int i, int target,
                vector<int>& nums,
                vector<vector<int>>& dp){

        if(target == 0)
            return true;

        if(i == 0)
            return nums[0] == target;

        if(dp[i][target] != -1)
            return dp[i][target];

        bool notTake = helper(i-1, target, nums, dp);

        bool take = false;

        if(nums[i] <= target)
            take = helper(i-1,
                          target-nums[i],
                          nums, dp);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        if(sum & 1)
            return false;

        int target = sum / 2;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target+1,-1));

        return helper(n-1,target,nums,dp);
    }
};

Idea 2:

class Solution {
public:
    bool helper(vector<int>& nums,int i,int sum,int tar,vector<vector<int>>& dp){
        if(i<0) return false;
        if(sum>tar) return dp[i][tar]=false;
        if(sum==tar) return dp[i][tar]=true;

        if(dp[i][tar]!=-1) return dp[i][tar];

        bool notTake=helper(nums,i-1,sum,tar,dp);
        bool take=helper(nums,i-1,sum+nums[i],tar-nums[i],dp);

        return dp[i][tar]=take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto x:nums) sum+=x;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return helper(nums,n-1,0,sum,dp);
    }
};
