https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n 
to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/2;

        vector<vector<int>> left(n+1),right(n+1);

        int total=0;
        for(auto x:nums) total+=x;

        //check all possibilites 2^n
        //it takes care of which ele to inclu and exclu based on bit wise and.
        for(int mask=0;mask<(1<<n);mask++){
            int cnt=0,sum=0;

            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    cnt++;
                    sum+=nums[i];
                }
            }
            left[cnt].push_back(sum);
        }

        for(int mask=0;mask<(1<<n);mask++){
            int cnt=0,sum=0;

            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    cnt++;
                    sum+=nums[n+i];
                }
            }
            right[cnt].push_back(sum);
        }

        //sort every cnt right sum arr as we are about to use Binary Search
        for(int i=0;i<=n;i++) sort(right[i].begin(),right[i].end());

        int ans=INT_MAX;
        //for each cnt of left subarr check for right sub arr
        for(int cnt=0;cnt<=n;cnt++){
            for(auto lsum:left[cnt]){
                int need=n-cnt;

                auto &vec=right[need];

                //for min abs diff (sum ==> almost near to total/2)
                int target=(total/2)-lsum;

                //gives ele >=tar
                auto it=lower_bound(vec.begin(),vec.end(),target);

                //check ele >=tar
                if(it!=vec.end()){
                    int s=lsum+*it;
                    ans=min(ans,abs(total-(2*s)));
                }

                //check ele just less than tar
                if(it!=vec.begin()){
                    --it;
                    int s=lsum+*it;
                    ans=min(ans,abs(total-(2*s)));
                }
            }
        }
        return ans;
    }
};
