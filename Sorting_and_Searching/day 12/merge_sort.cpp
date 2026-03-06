class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r) return;
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        
        int i=l,j=m+1;
        vector<int> temp;
        while(i<=m && j<=r){
            if(arr[i]<arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        while(i<=m) temp.push_back(arr[i++]);
        while(j<=r) temp.push_back(arr[j++]);
        for(int k=0;k<temp.size();k++){
            arr[l+k]=temp[k];
        }
    }
};
