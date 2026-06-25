https://leetcode.com/problems/validate-stack-sequences/description/

Given two integer arrays pushed and popped each with distinct values,
return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

Algo: 
      For every element in pushed:
              1. Push it.
              2. While the stack top matches the next element in popped, pop it.

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int j=0;
        stack<int> stk;
        for(int x:pushed){
            stk.push(x);
            while(!stk.empty() && j<n && stk.top()==popped[j]){
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};
