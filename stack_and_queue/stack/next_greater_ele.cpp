https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

You are given an array arr[] of integers, 
the task is to find the next greater element for each element of the array in order of their appearance in the array. 
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.

Algorithm:
      1. define a stack and come from last of given arr() [ for(i=n-1;i>=0;i--) ]
      2. pop ele which are <= arr[i]
      3. res[i]=stk.top();
      4. push arr[i] to stk (i.e stk.push(arr[i]) )

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=arr[i]){
                stk.pop();
            }
            if(!stk.empty())res[i]=stk.top();
            stk.push(arr[i]);
        }
        return res;
    }
};
