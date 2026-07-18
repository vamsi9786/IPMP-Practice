https://leetcode.com/problems/combination-sum/description/

Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

class Solution {
public:
    void helper(int idx,vector<int>& nums,int tar,vector<int>& ds,vector<vector<int>>& ans){
        if(idx>=nums.size() || tar<0) return;

        if(tar==0){
            ans.push_back(ds);
            return;
        }
        
        //take
        ds.push_back(nums[idx]);
        helper(idx,nums,tar-nums[idx],ds,ans);
        ds.pop_back();

        //not take
        helper(idx+1,nums,tar,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,arr,ans);
        return ans;
    }
};
