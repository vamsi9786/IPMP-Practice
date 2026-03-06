class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int idx1=0;
        if(matrix[0][0]>target){
            return false;
        }
        for(idx1=0;idx1<m;idx1++){
            if(matrix[idx1][0]<target && matrix[idx1][n-1]>target){
                break;
            }
            else if(matrix[idx1][0]==target || matrix[idx1][n-1]==target) return true;
        }
        if(idx1==m) idx1--;
        int l=0,r=n-1;
        while(l<=r && l>=0 && r<n){
            int md=l+((r-l)/2);
            if(matrix[idx1][md]==target) return true;
            else if(matrix[idx1][md]<target){
                l=md+1;
            }
            else if(matrix[idx1][md]>target){
                r=md-1;
            }
        }
        return false;
    }
};
