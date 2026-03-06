You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

algorithm:
    1. We cut the string only when we are sure that all characters seen so far will NOT appear again later.
    2. WHEN Does a Partition End?  
          We scan the string left to right and keep track of:
          end = the farthest last index of all characters seen so far
          start = starting index of current partition
                (i). end=max(end,last[s[i]-'a']);
                (ii).  i.e (end==i) -->cut here
  
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);

        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }

        vector<int> res;
        int st=0,end=0;

        for(int i=0;i<s.size();i++){
            end=max(end,last[s[i]-'a']);

            if(end==i){
                res.push_back(end-st+1);
                st=i+1;
            }
        }
        return res;
    }
};
