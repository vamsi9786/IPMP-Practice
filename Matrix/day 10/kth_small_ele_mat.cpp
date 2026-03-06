similar algo to median by in median req=(n*m)/2 but here req=k-1;

for counting no of ele less than mid i.e count 
we use 
      1. upper_bound i.e using binary search (used if each row is sorted ,each col may or may not)
            
      2. stair-case method (used if each row is sorted and each col is sorted)
          stair-case algo:
                (i). Start from bottom-left (or top-right) 
                (ii). Move:                 (moves right value increases , moves up value decreases)
                        Right if mat[i][j] ≤ mid     add count+=(i+1)             
                        Up if mat[i][j] > mid  
                  //staircase method
                  int countLessEqual(vector<vector<int>>& mat, int n, int mid) {
                    int count = 0;
                    int i = n - 1, j = 0;
                
                    while (i >= 0 && j < n) {
                        if (mat[i][j] <= mid) {
                            count += (i + 1);
                            j++;
                        } else {
                            i--;
                        }
                    }
                    return count;
                }

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n=mat.size();
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][n-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int c=0;
            for(int i=0;i<n;i++){
                c+=upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
            }
            if(c<=k-1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
