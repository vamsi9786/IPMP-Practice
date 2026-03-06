Algorithm
      1. intution: req capacity will be in between max wt and sum of all wts.  (max_wt <= req cap <= sum of all wt)
      2. take low = max_wt and high = sum of all wt
      3. do binary search on low and high and mid=low+(high-low)/2 and check will it be sufficient for given days 
              (i). if yes, then reduce high = mid;
              (ii). if no, increase low=mid+1;

class Solution {
public:
    bool candeliver(vector<int>& weights,int days,int cap){
        int currwt=0,reqdays=1;

        for(int w:weights){
            if(currwt+w > cap){
                reqdays++;
                currwt=w;
            }
            else{
                currwt+=w;
            }
        }
        return reqdays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }

        while(low<high){
            int mid=low+(high-low)/2;
            
            if(candeliver(weights,days,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
