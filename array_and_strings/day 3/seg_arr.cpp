class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int l=0;
        for(int r=0;r<arr.size();r++){
              if(arr[r]==0){
                    arr[l]=0;
                    l++;
              }
        }
        while(l<arr.size()){
              arr[l]=1;
              l++;
        }
    }
};
