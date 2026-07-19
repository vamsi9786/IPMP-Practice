https://leetcode.com/problems/longest-increasing-subsequence/description/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Methods: M1: Binary search O(n*logn)
         M2: Iterative dp O(n^2) O(n)
         M3: Memoization dp O(n^2) O(n^2)

//Patience Sorting + Binary search
Idea: for each int x ==> maintain tails arr which has highest ele as x in tail arr
               auto it = lower_bound(tails.begin(), tails.end(), x); ===> points to first ele >= x in tail arr
               *it = x; ==> maintains 
                suppose tails = {2,3,7,18}; and x = 5;

We do: auto it = lower_bound(tails.begin(), tails.end(), 5);
       The first element ≥5 is 7.
            2 3 7 18
                ^
                it
        Then ===> *it = 5;
        Now ===> 2 3 5 18

//Binary search O(nlogn)
//n*logn
class Solution {
public:
    int lowerBound(vector<int>& arr,int x){
        int l=0,h=arr.size()-1;
        int ans=arr.size();

        while(l<=h){
            int m=(l+h)/2;
            if(arr[m]>=x){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> arr;
        for(int x:nums){
            //we want first ele >=x in arr
            int it=lowerBound(arr,x);
            if(it==arr.size()){
                arr.push_back(x);
            }
            else{
                arr[it]=x;
            }
        }
        return arr.size();
    }
};
//O(nlogn) 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for (int x : nums) {

            auto it = lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end())
                tails.push_back(x);
            else
                *it = x;
        }

        return tails.size();
    }
};

//iterative O(n^2) O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//Memoization O(n^2) O(n^2)
class Solution {
public:
    int helper(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i<0) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int take=0;
        if(prev==nums.size() || nums[i]<nums[prev]){
            take=1+helper(i-1,i,nums,dp);
        }

        int notTake=helper(i-1,prev,nums,dp);

        return dp[i][prev]=max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return helper(n-1,n,nums,dp);
    }
};
*/

