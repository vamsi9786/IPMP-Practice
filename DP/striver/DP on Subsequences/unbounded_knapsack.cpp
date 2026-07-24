https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. 
Also, a knapsack with a weight limit capacity.

Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.

class Solution {
  public:
    int helper(int i,int wt,vector<pair<int,int>>& pii,vector<vector<int>>& dp){
        if(i<0 || wt<=0) return 0;
        
        if(dp[i][wt]!=-1) return dp[i][wt];
        
        int p=pii[i].first,w=pii[i].second;
        int take=0;
        if(w<=wt) take=p+helper(i,wt-w,pii,dp);
        int notTake=helper(i-1,wt,pii,dp);
        
        return dp[i][wt]=max(take,notTake);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<int,int>> pii;
        for(int i=0;i<n;i++){
            pii.push_back({val[i],wt[i]});
        }
        
        vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
        
        return helper(n-1,capacity,pii,dp);
    }
};
