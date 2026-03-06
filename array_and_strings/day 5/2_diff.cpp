/////////////////////////////
complexity O(n)  Hash map

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        int n=arr.size();
        unordered_map <int,int>mp;
        for(int y : arr){
            if(mp[y+x]>0 || mp[y-x]>0) return true;
            mp[y]++;
        }
        return false;
    }
};

////////////////////////////
complexity O(log n) 2 pointers


class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        int n=arr.size();
        int l=0,r=1;
        sort(arr.begin(),arr.end());
        while(l<n && r<n){
            int diff=arr[r]-arr[l];
            if(diff==x && l!=r) return true;
            else if(diff<x) r++;
            else l++;
            if(l==r) r++;
        }
        return false;
    }
};
