There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

    
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
    int search(vector<int>& nums, int target) {
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
        int idx;
        if(f) idx=r;
        else idx=l-1;
        int idx1=binsrch(nums,target,0,idx);
        int idx2=binsrch(nums,target,idx+1,n-1);
        if(idx1==-1 && idx2!=-1) return idx2;
        else if(idx1!=-1 && idx2==-1) return idx1;
        else return -1;
    }
};
