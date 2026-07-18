https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

class Solution {
public:
    void helper(int idx,string digits,string& s,vector<string>& mp,vector<string>& ans){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        for(char &ch:mp[digits[idx]-'2']){
            s.push_back(ch);
            helper(idx+1,digits,s,mp,ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mp(8);
        mp[0]="abc";mp[1]="def";mp[2]="ghi";mp[3]="jkl";mp[4]="mno";
        mp[5]="pqrs";mp[6]="tuv";mp[7]="wxyz";

        vector<string> ans;
        string s="";
        helper(0,digits,s,mp,ans);
        return ans;
    }
};
