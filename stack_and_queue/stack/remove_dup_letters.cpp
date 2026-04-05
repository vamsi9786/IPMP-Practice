https://leetcode.com/problems/remove-duplicate-letters/description/

Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Algorithm:
    1.  Store last index of each character
    2.  Traverse string
    3.  For each character:
              If already used → skip
              While:  (stack not empty AND top > current AND top appears later again) → pop
              Push current
              Mark visited
    4. Form string res by popping each stk.top()
    5. reverse res string

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        vector<int> last(26,-1);
        vector<int> vis(26,0);
        for(int i=0;i<s.length();i++) last[s[i]-'a']=i;

        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(vis[c-'a']) continue;

            while(!stk.empty() && stk.top()>c && last[stk.top()-'a']>i){
                vis[stk.top()-'a']=0;
                stk.pop();
            }
            stk.push(c);
            vis[c-'a']=1;
        }

        string res;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
