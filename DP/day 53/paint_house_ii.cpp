https://www.lintcode.com/problem/516
lintcode 516

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; 
costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.

Algo/Idea:
  Method 1: 1. Use iterative dp + (maintain min1 and min2 of prev house). ==> dp stores min costs all colors till that house from last house
            2. Follow step 3 & 4 for n-2 to 0 :
            3. find min of all dp costs from prev houses all colors min_of(dp[j]) j=0 to k. (min ===> min of all color costs of prev house)
                      store min1,min2 and idx ==> color of min1
            4. if min color is idx ==> new_dp[col]=costs[i][col]+min2; i.e skip prev_min_color
               else ==> new_dp[col]=costs[i][col]+min1;
            5. return min of all dp values i.e min of all costs of house 0

Method 1: O(nk)
class Solution {
public:
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
        if(n==0) return 0;

        int k=costs[0].size();
        if(k==0) return 0;

        vector<int> dp=costs[n-1];

        for(int i=n-2;i>=0;i--){
            int min1=INT_MAX;
            int min2=INT_MAX;
            int idx=-1;

            for(int j=0;j<k;j++){
                if(dp[j]<min1){
                    min2=min1;
                    min1=dp[j];
                    idx=j;
                }
                else if(dp[j]<min2){
                    min2=dp[j];
                }
            }

            vector<int> cur(k);
            for(int col=0;col<k;col++){
                if(col!=idx){
                    cur[col]=costs[i][col]+min1;
                }
                else{
                    cur[col]=costs[i][col]+min2;
                }
            }
            dp=cur;
        }

        return *min_element(dp.begin(),dp.end());
    }
};


Method 2: O(n * k^2)
//O(n*(k^2))
class Solution {
public:
    int n,k;
    int helper(int i,int col,vector<vector<int>>& costs,vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(dp[i][col]!=-1) return dp[i][col];

        int ans=INT_MAX;
        for(int idx=1;idx<k;idx++){
            int nextCol=(col+idx)%k;
            ans=min(ans,costs[i][col]+helper(i+1,nextCol,costs,dp));
        }

        return dp[i][col]=ans;
    }

    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        n=costs.size();
        if(n==0) return 0;

        k=costs[0].size();
        if(k==0) return 0;

        int ans=INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        for(int i=0;i<k;i++){
            ans=min(ans,helper(0,i,costs,dp));
        }

        return ans;
    }
};
*/
