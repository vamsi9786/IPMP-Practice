https://leetcode.com/problems/reverse-pairs/description/

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
      0 <= i < j < nums.length and
      nums[i] > 2 * nums[j].

Algo: use merge sort and during comparisions use x > 2*y cond for final ans count
  
class Solution {
public:
    int helper(vector<int>& nums,int l,int r){
        if(l>=r) return 0;
        int mid=(r+l)/2;
        int ans=0;
        ans+=helper(nums,l,mid);
        ans+=helper(nums,mid+1,r);

        //at this step left subarr sorted and right subarr sorted 
        int j=mid+1;
        for(int i=l;i<=mid;i++){
            while(j<=r && (long long)nums[i]>2LL*nums[j]) j++;
            ans+=j-(mid+1);
        }
        sort(nums.begin()+l,nums.begin()+r+1);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};
