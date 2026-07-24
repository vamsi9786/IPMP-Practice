https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

class Solution {
  public:
    int helper(int i,int tar,vector<int>& arr,vector<vector<int>>& dp){
        if(i==0){
            if(tar==0 && arr[0]==0) return 2;
            if(tar==0 || tar==arr[0]) return 1;
            return 0;
        }
        
        if(dp[i][tar]!=-1) return dp[i][tar];
        
        int take=0;
        if(tar>=arr[i]) take=helper(i-1,tar-arr[i],arr,dp);
        int notTake=helper(i-1,tar,arr,dp);
        
        return dp[i][tar]=take+notTake;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(n-1,target,arr,dp);
    }
};
