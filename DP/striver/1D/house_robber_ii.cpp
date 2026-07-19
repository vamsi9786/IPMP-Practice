https://leetcode.com/problems/house-robber-ii/description/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

//Method
===> Use 2 arr and find max of it arr1==>remove first ele arr2==>remove last ele

//iterative
int solve(vector<int>& nums, int l, int r){

    int prev2 = 0;
    int prev1 = 0;

    for(int i=l;i<=r;i++){
        int take = nums[i] + prev2;
        int skip = prev1;

        int cur = max(take, skip);

        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

//Recursive
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
        if(n==1) return nums[0];

        vector<int> arr1=nums;
        vector<int> arr2=nums;
        arr1.erase(arr1.begin());
        arr2.pop_back();
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        return max(helper(arr1,n-2,dp1),helper(arr2,n-2,dp2));
    }
};
