Algorithm:
      1. intution: req div lies b/w 1 and max of all no's in nums (1 <= req <= max_no in nums)
      2. low=1 , high= max_no , mid=low+(high-low)/2;
      3.     (i). if(sum of all divisons <= threshold) then high=mid;
             (ii). else low=mid+1;
      4. return low .

class Solution {
public:
    bool isdivsum(vector<int>& nums,int t,int div){
        int sum=0;
        for(int x:nums){
            int res=(x%div==0)?x/div:(x/div)+1;
            sum+=res;
            if(sum>t) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            high=max(high,nums[i]);
        }
        while(low<high){
            int mid=low+(high-low)/2;

            if(isdivsum(nums,threshold,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
