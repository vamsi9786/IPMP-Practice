https://leetcode.com/problems/next-greater-element-ii/

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.

Algorithm:
      1. define a stack and come from last of given arr() [ for(i=2*n-1;i>=0;i--) ]
      2. pop ele which are <= arr[i%n]
      3. if(i<n && !stk.empty())res[i]=stk.top();
      4. push arr[i%n] to stk (i.e stk.push(arr[i]) )

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> stk;
        vector<int> res(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=nums[i%n]){
                stk.pop();
            }
            if(i<n && !stk.empty()){
                res[i]=stk.top();
            }
            stk.push(nums[i%n]);
        }
        return res;
    }
};
