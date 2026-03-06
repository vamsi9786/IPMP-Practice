algorithm:
  1. transpose of matrix (swap mat[i][j], mat[j][i])
  2. for clockwise : reverse each row
     for anti-clockwise: reverse each column


void rotate(vector<vector<int> >& mat) {
    int m=mat.size();
    int n=mat[0].size();
    //find transpose of matrix
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    //for clockwise reverse each row
    for(int i=0;i<m;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}
