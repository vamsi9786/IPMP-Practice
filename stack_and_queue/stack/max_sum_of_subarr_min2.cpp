https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

You are given an array arr[] of integers. 
Your task is to find the maximum sum of the smallest and second smallest elements across all subarrays (of size >= 2) of the given array.


class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int ans=INT_MIN;
        for(int i=0;i<arr.size()-1;i++){
            ans=max(ans,arr[i]+arr[i+1]);
        }
        return ans;
    }
}; 
