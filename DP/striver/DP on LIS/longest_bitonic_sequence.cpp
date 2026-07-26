https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

Given an array of positive integers. Find the maximum length of Bitonic subsequence.  
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
Return the maximum length of bitonic subsequence.
 
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence.

Idea/Algo: For peak ele ==> bitonic ==> LIS ending at i + LDS starting at i 
           so for each ele find LIS ending at i and LDS starting at i
           take each ele as peak and calc Bitonic as max(ans, LIS[i]+LDS[i]-1) 
          ===> as no strictly increasing only and strictly decreasing only so ===> LIS[i]>1 && LDS[i]>1

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        
        //lis ending at i
        vector<int> lis(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(1+lis[j],lis[i]);
                }
            }
        }
        
        //lds starting at i
        vector<int> lds(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    lds[i]=max(1+lds[j],lds[i]);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1){
                ans=max(ans,lis[i]+lds[i]-1);
            }
        }
        
        return ans;
    }
};
