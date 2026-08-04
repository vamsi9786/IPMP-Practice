https://leetcode.com/problems/russian-doll-envelopes/description/

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelopes width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Idea/Algo: 
  Method 1: while sorting ==> if equal widths then sort in dec order of ht ===> this makes lis not to take both.
  Method 2: use lis O(n^2)

Method 1: O(n log(n)) ===> Binary Search
in lower bound fn ==> just ht is enough as width already in non-dec order

class Solution {
public:
    //just lowerBound based on ht is enough
    int lowerBound(vector<int>& temp,int x){
        int ans=temp.size();
        int low=0,high=ans-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(temp[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    //if width are equal then we sort dec of ht 
    //bcoz if asc then lis takes both so we use dec order 
    static bool cmp(const vector<int>& p1,const vector<int>& p2){
        if(p1[0]==p2[0]) return p1[1]>p2[1];
        return p1[0]<p2[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();

        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> temp;

        for(int i=0;i<n;i++){
            int it=lowerBound(temp,envelopes[i][1]);
            if(it==temp.size()){
                temp.push_back(envelopes[i][1]);
            }
            else{
                temp[it]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};


Method 2:

//TLE O(n^2)
class Solution {
public:
    static bool cmp(const vector<int>& p1,const vector<int>& p2){
        if(p1[0]==p2[0]) return p1[1]<p2[1];
        return p1[0]<p2[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();

        vector<int> dp(n,1);
        int ans=1;

        sort(envelopes.begin(),envelopes.end(),cmp);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


