https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

You are given a 0-indexed array of positive integers nums and a positive integer limit.
In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, 
array a has an element that is less than the corresponding element in b. 

For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

Idea/Algo: 1. sort the array nums. (Sort elements by value.)
           2. We dont need to compare every pair.
              Checking adjacent sorted values is enough because if two non-adjacent values are connected, 
              there must be a chain through adjacent values.
           3. To obtain the lexicographically smallest array,
                    smallest value → smallest index
                    second smallest value → second smallest index
                    ...


 ex: [5,1,3] 1<->5 not directly but can swap by using 5<->3 and 3<->1
      so sort the array and untill adjacent diff <= limit ===> store all idx in idx_arr and 
      sort the idx_arr and allocate them by sorted nums_arr 
      ex: 5,1,3 are at idx 0,4,6 ==> sort arr ==> 1,3,5 and allocate 1,3,5 at 0,4,6 (1 at 0 , 3 at 4, 5 at idx 6)
  
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> pii;
        for(int i=0;i<n;i++){
            pii.push_back({nums[i],i});
        }
        sort(pii.begin(),pii.end());

        vector<int> ans(n);
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && pii[j].first-pii[j-1].first <= limit) j++;

            vector<int> idx;
            for(int k=i;k<j;k++){
                idx.push_back(pii[k].second);
            }
            int k=i;
            sort(idx.begin(),idx.end());
            for(auto &x:idx){
                ans[x]=pii[k++].first;
            }
            i=j;
        }
        return ans;
    }
};
