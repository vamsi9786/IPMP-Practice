temp[i][j] is min ele in sub_matrix (0,0) to (i,j)

class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat, int N) {
        int ans=INT_MIN;
        int n=N;
        vector<vector<int>> temp(n,vector<int>(n));
        temp[0][0]=mat[0][0];
        for(int i=1;i<n;i++){
            temp[i][0]=min(temp[i-1][0],mat[i][0]);
        }
        for(int i=1;i<n;i++){
            temp[0][i]=min(temp[0][i-1],mat[0][i]);
        }
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                ans=max(ans,mat[i][j]-temp[i-1][j-1]);
                temp[i][j]=min({mat[i][j],temp[i-1][j],temp[i][j-1]});
            }
        }
        return ans;
    }
};
