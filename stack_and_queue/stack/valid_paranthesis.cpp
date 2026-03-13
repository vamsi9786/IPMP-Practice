Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

class Solution {
public:
    bool cmpchar(char c1,char c2){
        if(c1=='(' && c2==')') return true;
        else if(c1=='{' && c2=='}') return true;
        else if(c1=='[' && c2==']') return true;
        return false;
    }
    bool isValid(string s) {
        int n=s.length();
        stack<char> stk;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                else{
                    if(!cmpchar(stk.top(),s[i])) return false;
                    else stk.pop();
                }
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};


Cleaner version

class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;

        for(char c : s){

            if(c=='(' || c=='{' || c=='[')
                stk.push(c);
            else{

                if(stk.empty()) return false;

                char top = stk.top();
                stk.pop();

                if((top=='(' && c!=')') ||
                   (top=='{' && c!='}') ||
                   (top=='[' && c!=']'))
                    return false;
            }
        }

        return stk.empty();
    }
};
