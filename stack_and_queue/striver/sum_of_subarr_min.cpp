https://leetcode.com/problems/sum-of-subarray-minimums/description/

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 10^9 + 7.

Idea: 
     1. For every element, in how many subarrays is it the minimum? then contibute: ( arr[i] × number_of_subarrays )
     2. How to Count?
          For every element: Using stack Compute Previous Smaller Element (PSE) and  Next Smaller Element (NSE)
                        left = distance to previous smaller
                        right = distance to next smaller
                        No. of subarrays = left × right
                        Overall Contribution: arr[i] × left × right

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        int n=arr.size();
        vector<int> left(n),right(n);

        //left minimum idx for each i
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            left[i]=(stk.empty())?-1:stk.top();
            stk.push(i); 
        }

        while(!stk.empty()) stk.pop();

        //right mininum idx for each i
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            right[i]=(stk.empty())?n:stk.top();
            stk.push(i);
        }

        long long ans=0;
        long long mod=1e9+7;

        //count ans
        for(int i=0;i<n;i++){
            long long l=i-left[i];
            long long r=right[i]-i;
            ans=(ans+((l*r)%mod)*arr[i])%mod;
        }
        return ans;
    }
};
