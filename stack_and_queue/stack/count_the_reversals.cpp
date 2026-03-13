https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/

Given a string s consisting of only opening and closing curly brackets '{' and '}', 
find out the minimum number of reversals required to convert the string into a balanced expression. 
A reversal means changing '{' to '}' or vice-versa.

Algorithm:
    1. remove all good paranthesis . in final stack there will be paranthesis which need to be modified
    2. in final stack it may be [[[[[[[[ or ]]]]]]]]
  

class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        int n=s.length(),ans=0;
        if(n%2!=0) return -1;
        stack<char> stk;
      
        for(int i=0;i<n;i++){
            if(s[i]=='{') stk.push(s[i]);
            else{
                if(!stk.empty() && stk.top()=='{') stk.pop();
                else stk.push(s[i]);
            }
        }

        <===============================>
        while(!stk.empty()){
            char top=stk.top();
            stk.pop();
            if(!stk.empty()){
                if(top==stk.top()){
                    ans++;stk.pop();
                }
                else if(top=='{' && stk.top()=='}'){
                    ans+=2;stk.pop();
                }
            }
        }
        return ans; 
      <=================================>

        we could use this (i.e find no of open and close brackets count and find res)
      <================================>
        while(!stk.empty()){
            if(stk.top() == '{') open++;
            else close++;
            stk.pop();
        }

        return (open+1)/2 + (close+1)/2;
      <==================================>
    }
};
