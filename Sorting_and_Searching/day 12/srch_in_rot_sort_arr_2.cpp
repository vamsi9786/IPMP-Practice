There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.

class Solution {
public:
    int binsrch(vector<int>& nums,int tar,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==tar) return mid;
            else if(nums[mid]>tar) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=1,r=n-2,f=0;
        while(l<=r){
            if(nums[l-1]>nums[l]){
                break;
            }
            if(nums[r]>nums[r+1]){
                f=1;
                break;
            }
            l++;r--;
        }
        int idx=(n/2);
        if(f) idx=r;
        else idx=l-1;
        int idx1=binsrch(nums,target,0,idx);
        int idx2=binsrch(nums,target,idx+1,n-1);
        return (idx1!=-1 || idx2!=-1);
    }
};
