algorithm:
1.  we need to find no of ele <=k i.e good elements.
2. we need subarr such that all ele<=k so we need sliding window of size good ele.
3. in each window find no of ele>k bad ele.
4. min swaps so we need min of bad ele.


class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n=arr.size();
        int good=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k) good++;
        }
        //find no of good elements
        //we need window of length good
        int bad=0;
        for(int i=0;i<good;i++){
            if(arr[i]>k) bad++;
        }
        int ans=bad;
        for(int i=good;i<n;i++){
            if(arr[i-good]>k) bad--; //leaving ele
            if(arr[i]>k) bad++; //entering ele
            ans=min(ans,bad);
        }
        return ans;
    }
};
