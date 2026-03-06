algorithm :
  1. find min ele and max ele in whole matrix
  2. using binary search 
        (i). mid=low+(high-low)/2
        (ii). count no of ele in whole matrix which are <= req (req= (n*m)/2)
        (iii). low<=high 
                if (count<=req) low=mid+1; (i.e median is greater than mid)
                else high=mid-1;  (i.e median is less than mid)
        (iv). return low

class Solution {
  public:
    int countno(vector<int>& row,int k){
        int l=0,r=row.size();
        while(l<r){
            int m=l+(r-l)/2;
            if(row[m]<=k){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return l;
    }
  
    int median(vector<vector<int>> &mat) {
        int m=mat.size();
        int n=mat[0].size();
        int req=(m*n)/2;
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<m;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][n-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int c=0;
            for(int i=0;i<m;i++){
                c+=countno(mat[i],mid);
            }
            if(c<=req){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
