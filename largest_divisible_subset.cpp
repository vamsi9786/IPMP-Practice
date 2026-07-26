https://leetcode.com/problems/largest-divisible-subset/description/

Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
  (answer[i], answer[j]) of elements in this subset satisfies: answer[i] % answer[j] == 0, or answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

Idea/Algo: Method 1: use iterative LIS and construct result from dp table
           Method 2: use iterative LIS and use parent array to construct result and maintain last idx ==> last idx of LIS
                      init par[i]=i 
                      then for each j ===> check (nums[i]%nums[j]==0 && dp[j]+1>dp[i]) and update par[i]=j; dp[i]=1+dp[j];
                      in each i ==> if(dp[i]>maxlen){ maxlen=dp[i]; and last_idx=i; } 

Method 1:
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
    
        vector<int> dp(n+1,1);

        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }

        //Construct LIS from dp table
        vector<int> res;
        int last_idx=0;
        //find last index of LIS
        for(int i=n-1;i>=0;i--){
            if(dp[i]==ans){
                last_idx=i;
                break;
            }
        }
        res.push_back(nums[last_idx]);

        int currLen=ans;
        int currVal=nums[last_idx];
        //check whether nums[j] part of LIS or not
        //if yes then add to res arr
        for(int j=last_idx-1;j>=0;j--){
            if(dp[j]==currLen-1 && currVal%nums[j]==0){
                res.push_back(nums[j]);
                currVal=nums[j];
                currLen--;
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};


Method 2:
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxi = 1;
        int lastIndex = 0;

        for(int i = 0; i < n; i++) {

            parent[i] = i;

            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0 &&
                   dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if(dp[i] > maxi) {

                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;

        while(parent[lastIndex] != lastIndex) {

            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        ans.push_back(nums[lastIndex]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
