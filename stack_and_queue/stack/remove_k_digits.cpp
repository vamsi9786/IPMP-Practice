https://leetcode.com/problems/remove-k-digits/

Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.

  Algorithm: Maintain a monotonic increasing stack
        1. remove bigger digits when a smaller digit appears
        bcoz Leftmost digits matter more (higher place value)


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for(char c: num){
            while(!stk.empty() && k>0 && stk.top()>c){
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        while(k>0 && !stk.empty()){
            stk.pop();k--;
        }
        string res;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size() && res[i]=='0') i++;
        res=res.substr(i);
        return res==""?"0":res;
    }
};
