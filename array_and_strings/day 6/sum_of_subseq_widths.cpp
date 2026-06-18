https://leetcode.com/problems/sum-of-subsequence-widths/description/

The width of a sequence is the difference between the maximum and minimum elements in the sequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

sol: idea: For each sequence, 
                    Instead of calculating width = max-min
                    we calculate as ("contibution of nums[i] as max " - " contibution of nums[i] as max ")
  Algo: 1. Sort the arr: sort(nums.begin(),nums.end());
        2. For each nums[i]: nums[i] is max for 'i' elements and min for 'n-i-1' ele
          so final ans is Summation(nums[i]* (pow(2,i)-pow(2,n-i-1)))

  
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int MOD=1e9+7;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> power(n);
        power[0]=1;
        for(int i=1;i<n;i++) power[i]=(power[i-1]*2)%MOD;
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+nums[i]*(power[i]-power[n-i-1]))%MOD;
        }
        ans=(ans+MOD)%MOD;
        return ans;
    }
};
