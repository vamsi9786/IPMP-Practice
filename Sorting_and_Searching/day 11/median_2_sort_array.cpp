O(log(range) * (log(m) + log(n)) )

class Solution {
public:
    int kthele(vector<int>& nums1,vector<int>& nums2,int req){
        int m=nums1.size(),n=nums2.size();
        int low=min(nums1.empty() ? INT_MAX : nums1[0], nums2.empty() ? INT_MAX : nums2[0]);
        int high=max(nums1.empty() ? INT_MIN: nums1[m-1], nums2.empty() ? INT_MIN : nums2[n-1]);

        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0;
            count += upper_bound(nums1.begin(),nums1.end(),mid) - nums1.begin();
            count += upper_bound(nums2.begin(),nums2.end(),mid) - nums2.begin();
            if(count<=req) low=mid+1;
            else high=mid-1;
        }
        return low;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int t=m+n;
        if(t%2==0){
            int a=kthele(nums1,nums2,(t/2)-1);
            int b=kthele(nums1,nums2,t/2);
            return (a+b)/2.0;
        }
        else{
            return kthele(nums1,nums2,t/2);
        }
    }
};

O(log(n+m))
Algorithm:
  1. we split nums1 into L1 and R1 and nums2 into L2 and R2 (always nums1 is smaller array size if m>n swap nums1 and nums2)
  2. we need partition such that
          L1=left ele of Left array of nums1
          R1=right ele of right array of nums1
          L2=left ele of Left array of nums2
          R2=right ele of right array of nums2
    correct partiton is L1<=R2 and L2<=R1
  3. We binary search on the index i (how many elements we take from nums1).
      For every choice of i: j= (m+n+1)/2 - i;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];

            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            if (L1 <= R2 && L2 <= R1) {
                // Correct partition found
                if ((m + n) % 2 == 0)
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                else
                    return max(L1, L2);
            }
            else if (L1 > R2) {
                high = i - 1; // move left
            }
            else {
                low = i + 1;  // move right
            }
        }
        return 0.0; // never reached
    }
};

