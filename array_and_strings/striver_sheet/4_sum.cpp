https://leetcode.com/problems/4sum/description/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] 
such that:
      0 <= a, b, c, d < n
      a, b, c, and d are distinct.
      nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

  Algo:
      1. Sort the array.
      2. Fix first element. Skip duplicate first.
      3. Fix second element. Skip duplicate second
      4. Use 2 pointers.

| Problem | Approach              | Complexity |
| ------- | --------------------- | ---------- |
| 2 Sum   | HashMap / Two Pointer | O(n)       |
| 3 Sum   | Fix 1 + Two Pointer   | O(n²)      |
| 4 Sum   | Fix 2 + Two Pointer   | O(n³)      |
| 5 Sum   | Fix 3 + Two Pointer   | O(n⁴)      |


General k-Sum Template
      1. Sort.
      2. Fix one element.
      3. Recursively solve (k-1)-Sum
  
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum<target) l++;
                    else if(sum>target) r--;
                    else{
                        vector<int> temp={nums[i],nums[j],nums[l],nums[r]};
                        res.push_back(temp);
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++;r--;
                    }
                }
            }
        }
        return res;
    }
};
