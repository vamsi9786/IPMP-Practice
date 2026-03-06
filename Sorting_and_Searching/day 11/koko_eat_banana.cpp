Algorithm
      1. intution: req k will be in between 1 and max of all piles wts.  (1 <= req cap <= max of all piles)
      2. take low = 1 and high = max_wt
      3. do binary search on low and high and mid=low+(high-low)/2 and check will it be sufficient for given hours 
              (i). if yes, then reduce high = mid;
              (ii). if no, increase low=mid+1;


class Solution {
public:
    bool willfinish(vector<int>& piles,int h,int k){
        int hr=0;
        for(int x:piles){
            hr+=(x%k==0)?x/k:(x/k)+1;
            if(hr>h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }

        while(low<high){
            //vector<int> temp=piles;
            int mid=low+(high-low)/2;
            if(willfinish(piles,h,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
