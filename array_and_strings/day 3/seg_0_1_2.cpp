
// Easy Approach count no of 0's , 1's , 2's
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int z=0,o=0,t=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) z++;
            else if(arr[i]==1) o++;
            else t++;
        }
        for(int i=0;i<z;i++) arr[i]=0;
        for(int i=z;i<z+o;i++) arr[i]=1;
        for(int i=z+o;i<arr.size();i++) arr[i]=2;
    }
};

//Interview expected "Dutch National flag algo"

class Solution {
  public:
    void sort012(vector<int>& arr) {
      int low=0,mid=0,high=arr.size()-1;
      while(mid<=high){
        if(arr[mid]==0){
          swap(arr[mid],arr[low]);
          low++;
        }
        else if(arr[mid]==1){
          mid++;
        }
        else{
          swap(arr[mid],arr[high]);
          high--;
        }
      }
    }
};
