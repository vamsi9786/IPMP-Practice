https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

class Solution {
public:
    bool canmake(vector<int>& bloomDay,int m,int mid,int k){
        int cnt=0,bq=0,n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
                if(cnt==k){
                    cnt=0;bq++;
                }
            }
            else cnt=0;
        }
        return bq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=INT_MAX,high=INT_MIN;
        int result=-1;
        for(int i=0;i<n;i++){
            high=max(high,bloomDay[i]);
            low=min(low,bloomDay[i]);
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(canmake(bloomDay,m,mid,k)){
                result=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return result;
    }
};
