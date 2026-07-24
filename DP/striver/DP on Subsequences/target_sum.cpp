https://leetcode.com/problems/target-sum/description/

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a + before 2 and a - before 1 and concatenate them to build the expression +2-1.
Return the number of different expressions that you can build, which evaluates to target.

//Memoization
class Solution {
public:
    int total;
    int helper(int i,vector<int>& nums,int sum,int tar,vector<vector<int>>& dp){
        if(i<0){
            return (sum==tar)?1:0;
        }
        if(dp[i][total+sum]!=-1) return dp[i][total+sum];

        int plus=helper(i-1,nums,sum+nums[i],tar,dp);
        int minus=helper(i-1,nums,sum-nums[i],tar,dp);
        return dp[i][sum+total]=plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        total=0;
        for(int &x:nums) total+=x;
        
        vector<vector<int>> dp(n,vector<int>(2*total+1,-1));
        return helper(n-1,nums,0,target,dp);
    }
};

//recursive without memoization
class Solution {
public:
    int helper(int i,vector<int>& nums,int sum,int tar,vector<vector<int>>& dp){
        if(i<0){
            return (sum==tar)?1:0;
        }
        int plus=helper(i-1,nums,sum+nums[i],tar,dp);
        int minus=helper(i-1,nums,sum-nums[i],tar,dp);
        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp;
        return helper(n-1,nums,0,target,dp);
    }
};
