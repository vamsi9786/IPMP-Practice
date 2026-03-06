// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int ans=0,idx=-1;
        int m=arr.size(),n=arr[0].size();
        for(int i=0;i<n;i++){
            if(arr[0][i]==1){
                ans=max(ans,n-i);
                idx=0;
                break;
            }
        }
        for(int i=1;i<m;i++){
            while(n-ans-1>=0 && arr[i][n-ans-1]==1){
                ans++;
                idx=i;
            }
        }
        return idx;
    }
};
