/////////////////////////
complexity O(n) Hash map

#include <bits/stdc++.h>
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map <int,int>mp;
        for(int x : arr){
            int need=target-x;
            if(mp[need]>0) return true;
            mp[x]++;
        }
        return false;
        
    }
};

///////////////////////////
complexity O(log n)
#include <bits/stdc++.h>

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=0,r=n-1;
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum==target) return true;
            else if(sum<target){
                l++;
            }
            else r--;
        }
        return false;
    }
};
