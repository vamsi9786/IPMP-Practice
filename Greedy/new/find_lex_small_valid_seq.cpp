https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08

You are given two strings word1 and word2.

A string x is called almost equal to y if you can change at most one character in x to make it identical to y.

A sequence of indices seq is called valid if:
          The indices are sorted in ascending order.
          Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
  
Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. 
If no such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

Algo/Idea: 1. Build suff[] ==> Greedily matches word2 from right to left.
              If suff[k] exists, then word2[k...m-1] can be matched starting at suff[k] and moving right.
           2. Greedily choose matching characters. if(i<n && word1[i]==word2[j]) ==> res.push_back(i)
           3. When current character does not match:
                      You can use your one mismatch: (but cant take blindly) 
                            You need to make sure the remaining characters: word2[j+1 ... m-1] can still be matched after this index.
                            ===> if(j+1==m || (suff[j+1]!=-1 && suff[j+1]>i))

Method 1:

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n<m) return {};

        vector<int> suff(m+1,-1);
        int p=n-1;

        for(int i=m-1;i>=0;i--){
            while(p>=0 && word1[p]!=word2[i]) p--;

            if(p<0) break;

            suff[i]=p;
            p--;
        }

        int j=0;
        int i=0;
        bool used=false;
        vector<int> ans;

        while(j<m){
            if(i<n && word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!used && i<n){
                //remaining word2[j+1....] must be possible
                if(j+1==m || (suff[j+1]!=-1 && suff[j+1]>i)){
                    ans.push_back(i);
                    j++;
                    used=true;
                }
            }
            i++;

            if(i>n) return {};
        }
        return ans;
    }
};


Method 2:
//recursion
//TLE
class Solution {
public:
    int n1,n2;
    vector<int> res;
    void helper(int i,int j,int flag,vector<int>& arr,string& s1,string& s2){
        if(j==n2){
            if(res.empty() || arr<res){
                res=arr;
            }
            return;
        }
        if(i>=n1) return;

        int ans=0;
        if(s1[i]==s2[j]){
            arr.push_back(i);
            helper(i+1,j+1,flag,arr,s1,s2);
            arr.pop_back();
        }
        if(flag){
            arr.push_back(i);
            helper(i+1,j+1,0,arr,s1,s2);
            arr.pop_back();
        }
        helper(i+1,j,flag,arr,s1,s2);
    }

    vector<int> validSequence(string word1, string word2) {
        n1=word1.size();
        n2=word2.size();
        if(n1<n2) return {};

        vector<int> arr;
        helper(0,0,1,arr,word1,word2);

        return res;
    }
};
