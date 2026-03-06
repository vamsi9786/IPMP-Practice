class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            int mx=max(arr[i]+k,arr[n-1]-k);
            int mi=min(arr[0]+k,arr[i+1]-k);
            if(mi<0) continue;
            ans=min(ans,mx-mi);
        }
        return ans;
    }
};
