
Given a string s consisting only of opening and closing parentheses '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.
Note: The length of the smallest valid substring "()" is 2.


class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int res=0;
        int n=s.length();
        stack<int> stk;
        stk.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(') stk.push(i);
            else{
                stk.pop();
                if(stk.empty()) stk.push(i);
                else res=max(res,i-stk.top());
            }
        }
        return res;
    }
};
