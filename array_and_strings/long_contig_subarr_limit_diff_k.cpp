https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the 
absolute difference between any two elements of this subarray is less than or equal to limit.

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int l=0,ans=0;
        deque<int> mindq,maxdq;
        
        for(int r=0;r<n;r++){
            //remove all ele less than nums[r]
            while(!maxdq.empty() && nums[maxdq.back()]<nums[r]){
                maxdq.pop_back();
            }
            //remove all ele > than nums[r]
            while(!mindq.empty() && nums[mindq.back()]>nums[r]){
                mindq.pop_back();
            }

            //push r
            maxdq.push_back(r);
            mindq.push_back(r);

            //if max-min > limit then pop window until <=limit
            while(nums[maxdq.front()]-nums[mindq.front()]>limit){
                if(maxdq.front()==l) maxdq.pop_front();
                if(mindq.front()==l) mindq.pop_front();
                l++;
            }

            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
