algorithm:
  Cut after index i if the largest value so far is not greater than the smallest value remaining.
  A cut happens exactly when the left part is completely independent of the right part with respect to sorting.
  ***maintain rightmin and leftmax if( leftmax[i] <= rightmin[i+1] ) make a chunk

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //Cut after index i if the largest value so far is not greater than the smallest value remaining.
        int n=arr.size();
        vector<int> rightMin(n+1,INT_MAX);

        for(int i=n-1;i>=0;i--){
            rightMin[i]=min(rightMin[i+1],arr[i]);
        }
        int ans=0;
        int maxLeft=INT_MIN; //max ele so far
        for(int i=0;i<n;i++){
            maxLeft=max(maxLeft,arr[i]);
            if(maxLeft<=rightMin[i+1]){
                ans++;
            }
        }
        return ans;
    }
};
