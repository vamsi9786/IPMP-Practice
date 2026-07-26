https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Idea/Algo: maintain cnt array of LIS cnt at that idx.
           2 cases: 
              1. found longer LIS ==> if(1+dp[j] > dp[i]) then update dp[i] and cnt[i] as (cnt[i]=cnt[j])
              2. found existing LIS len ==> 1+dp[j]==dp[i] then cnt[i]=cnt[i]+cnt[j]

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);

        int ans=1;
        vector<int> cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){

                    //found longer LIS
                    if(1+dp[j] > dp[i]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }

                    //found existing LIS len
                    else if(1+dp[j]==dp[i]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            ans=max(ans,dp[i]);
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ans) res+=cnt[i];
        }
        return res;
    }
};
