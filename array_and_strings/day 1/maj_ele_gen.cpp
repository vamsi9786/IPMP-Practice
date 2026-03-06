class Solution {
  public:
    int countOccurence(vector<int>& arr, int k) {
        int x=0,n=arr.size(),l=n/k,c=0;
        sort(arr.begin(),arr.end());
        if(n<k) return 0;
        else{
            int i=0;
            while(i<n){
                if(i+l<n && arr[i]==arr[i+l]){
                    c++;
                    int e=arr[i];
                    while(i<n && arr[i]==e) i++;
                }
                else i++;
            }
        }
        return c;
    }
};
