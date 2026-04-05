https://leetcode.com/problems/backspace-string-compare/description/

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Method-1: Two Pointers time: O(n) && space: O(1)

  class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while(i >= 0 || j >= 0){ 
            // process s
            while(i >= 0){
                if(s[i] == '#'){
                    skipS++; i--;
                }
                else if(skipS > 0){
                    skipS--; i--;
                }
                else break;
            }

            // process t
            while(j >= 0){
                if(t[j] == '#'){
                    skipT++; j--;
                }
                else if(skipT > 0){
                    skipT--; j--;
                }
                else break;
            }

            // compare characters
            if(i >= 0 && j >= 0){
                if(s[i] != t[j]) return false;
            }
            else{
                if(i >= 0 || j >= 0) return false;
            }

            i--; j--;
        }

        return true;
    }
};

  
Method-2: Stack time: O(n) && space: O(n)
  
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1;
        stack<char> stk2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!stk1.empty())stk1.pop();
            }
            else stk1.push(s[i]);
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!stk2.empty()) stk2.pop();
            }
            else stk2.push(t[i]);
        }
        string res1,res2;
        while(!stk1.empty()){
            res1+=stk1.top();
            stk1.pop();
        }
        reverse(res1.begin(),res1.end());
        while(!stk2.empty()){
            res2+=stk2.top();
            stk2.pop();
        }
        reverse(res2.begin(),res2.end());
        return res1==res2;
    }
};
