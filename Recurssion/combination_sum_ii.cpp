https://leetcode.com/problems/combination-sum-ii/description/

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

class Solution {
public:
    void helper(int idx,vector<int>& nums,int tar,vector<int>& ds,vector<vector<int>>& ans){
        if(tar==0){
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>tar) break;
            ds.push_back(nums[i]);
            helper(i+1,nums,tar-nums[i],ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,ds,ans);
        return ans;
    }
};
