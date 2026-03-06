https://leetcode.com/problems/next-greater-element-ii/


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
