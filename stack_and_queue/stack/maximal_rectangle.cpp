https://leetcode.com/problems/maximal-rectangle/description/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Using stack


















Using DP

For each cell (i,j), compute: number of consecutive 1s ending at (i,j) in the current row.
How to Find Rectangle? Treat each cell (i,j) as the bottom-right corner of a rectangle.
  dp[i][j] = 4 This means the current row can contribute a width of 4.
  Now move upward: width = min(width, dp[k][j]) because all rows in the rectangle must support the same width.
  area becomes ans=max(ans,width*(i-k+1));

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        //build dp table as each entry contains max width of consecutive 1's till idx j in ith row
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=(j==0)?1:dp[i][j-1]+1;
                }
            }
        }

        //for each entry if dp[i][j]!=0 
        //   for each above row,untill j idx calc max ans  


        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==0) continue;

                int width=dp[i][j];
                for(int k=i;k>=0;k--){
                    if(dp[k][j]==0) break;
                    width=min(width,dp[k][j]);
                    ans=max(ans,width*(i-k+1));
                }
            }
        }
        return ans;

    }
};
