https://www.geeksforgeeks.org/problems/counting-sort/1

Given a string s consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort

class Solution {
  public:
    string countSort(string s) {
        vector<int> arr(26,0);
        string res;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            while(arr[i]--){
                res.push_back('a'+i);
            }
        }
        return res;
    }
};
