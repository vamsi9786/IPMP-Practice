https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

Given an array arr[] and an integer diff, count the number of ways to partition the array into two subsets such that 
the difference between their sums is equal to diff.

Note: A partition in the array means dividing an array into two subsets say S1 and S2 such that the union of S1 and S2 is 
equal to the original array and each element is present in only one of the subsets.

Idea/Method: 1. calc s=sum_so_far and calc diff diff=total-(2*s) and check if diff===given_diff
             2. s1-s2=diff and s1+s2=total ===> s1=(total+diff)/2 and then do target sum

Method 1:
class Solution {
  public:
    int total;
    
    int helper(int i,int sum,vector<int>& arr,int diff,vector<vector<int>>& dp){
        if(i<0) return (total-(2*sum) == diff);
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        
        int take=helper(i-1,sum+arr[i],arr,diff,dp);
        int notTake=helper(i-1,sum,arr,diff,dp);
        
        return dp[i][sum]=take+notTake;
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        total=0;
        for(auto &x:arr) total+=x;
        vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
        
        return helper(n-1,0,arr,diff,dp);
    }
};

Method 2:
class Solution {
public:

    int helper(int i, int sum,
               vector<int>& arr,
               vector<vector<int>>& dp){

        if(i == 0){

            if(sum == 0 && arr[0] == 0)
                return 2;

            if(sum == 0 || sum == arr[0])
                return 1;

            return 0;
        }

        if(dp[i][sum] != -1)
            return dp[i][sum];

        int notTake = helper(i-1, sum, arr, dp);

        int take = 0;

        if(arr[i] <= sum)
            take = helper(i-1, sum-arr[i], arr, dp);

        return dp[i][sum] = take + notTake;
    }

    int countPartitions(vector<int>& arr, int diff){

        int total = accumulate(arr.begin(), arr.end(), 0);

        if(abs(diff) > total)
            return 0;

        if((total + diff) % 2)
            return 0;

        int target = (total + diff) / 2;

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target+1,-1));

        return helper(n-1, target, arr, dp);
    }
};
