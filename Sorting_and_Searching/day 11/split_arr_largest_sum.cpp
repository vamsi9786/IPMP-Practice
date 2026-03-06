Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Algorithm
      Step 1: low=max(nums[i]) ,high=sum(nums[i]) all ele in nums ,mid=low+(high-low)/2
      Step 2: Feasibility Check (Greedy),   Given a guessed value mid (maximum allowed subarray sum):
            Start with:
            count = 1 (number of subarrays), currentSum = 0
            Traverse the array from left to right:
                    If (currentSum + nums[i] ≤ mid )  → currentSum+=x; (x=nums[i])
                    Else{
                        → start a new subarray i.e count++;
                        → set currentSum = nums[i]
                        If count > k → not feasible
                    }
            If all elements are assigned using ≤ k subarrays → feasible
      Step 3:  binary search low==high
                    if(willsplit(nums,k,mid)) then high=mid;
                    else low=mid+1;
      Step 4: return low;

class Solution {
public:
    bool willsplit(vector<int>& nums,int k,int m){
        int c=1,curr=0;
        for(int x:nums){
            if(x>m) return false;
            if(x+curr<=m){
                curr+=x;
            }
            else{
                c++;
                curr=x;
                if(c>k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0;
        for(int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(willsplit(nums,k,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
