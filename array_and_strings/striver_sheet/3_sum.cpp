https://leetcode.com/problems/3sum/description/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Algo: 1. Sort.
      2. Fix first element and Use two pointers for remaining part.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=n-1;
            while(l<r){
                long long sum=(long long)nums[i]+nums[l]+nums[r];
                if(sum<0) l++;
                else if(sum>0) r--;
                else{
                    vector<int> temp(3);
                    temp[0]=nums[i];temp[1]=nums[l];temp[2]=nums[r];
                    res.push_back(temp);

                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }
            }
        }
        return res;
    }
};
