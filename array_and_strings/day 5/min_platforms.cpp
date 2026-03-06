class Solution {
  public:
    
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int i=0,j=0,n=arr.size(),ans=0,pt=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                pt++;
                ans=max(ans,pt);
                i++;
            }
            else{
                pt--;
                j++;
            }
        }
        return ans;
    }
};
