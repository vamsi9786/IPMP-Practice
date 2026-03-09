https://leetcode.com/problems/daily-temperatures/

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Algorithm: Monotonic stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[stk.top()]<=temperatures[i]) stk.pop();
            if(!stk.empty()){
                res[i]=stk.top()-i;
            }
            stk.push(i);
        }
        return res;
    }
};
