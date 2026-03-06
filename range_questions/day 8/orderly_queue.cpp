You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string.
Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

Algorithm:
  1. if k>1 it will become string in sorted
  2. return least lexicographically ordered after first ele rotation for k-1 times
  
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        string temp=s;
        for(int i=1;i<s.size();i++){
            rotate(temp.begin(),temp.begin()+1,temp.end());
            ans=min(ans,temp);
        }
        return ans;
    }
};
