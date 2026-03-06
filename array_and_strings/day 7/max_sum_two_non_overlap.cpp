O(n^3)

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int k1=firstLen;
        int k2=secondLen;
        int n=nums.size();
        int mx=INT_MIN,sum1=0,sum2=0;
        for(int i=0;i<k1;i++){
            sum1=sum1+nums[i];
        }
        for(int i=k1;i<k1+k2;i++){
            sum2=sum2+nums[i];
        }
        mx=max(mx,sum1+sum2);
        for(int i=k1+1;i<=n-k2;i++){
            sum2=sum2-nums[i-1]+nums[i+k2-1];
            mx=max(mx,sum1+sum2);
        }
        for(int i=1;i<=n-k1;i++){
            sum1=sum1-nums[i-1]+nums[i+k1-1];
            sum2=0;
            for(int j=0;j<=i-k2;j++){
                if(j==0){
                    for(int k=0;k<k2;k++){
                        sum2+=nums[k];
                    }
                    mx=max(mx,sum1+sum2);
                }
                else{
                    sum2=sum2-nums[j-1]+nums[j+k2-1];
                    mx=max(mx,sum1+sum2);
                }
            }
            sum2=0;
            for(int j=i+k1;j<=n-k2;j++){
                if(j==i+k1){
                    for(int k=i+k1;k<i+k1+k2;k++){
                        sum2+=nums[k];
                    }
                    mx=max(mx,sum1+sum2);
                }
                else{
                    sum2=sum2-nums[j-1]+nums[j+k2-1];
                    mx=max(mx,sum1+sum2);
                }
            }
        }
        return mx;
    }
};


o(n)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pre(n+1, 0); // prefix sums
        for(int i=0; i<n; i++) pre[i+1] = pre[i] + nums[i];

        auto maxSum = [&](int L, int M) {
            int maxL = pre[L] - pre[0]; // sum of first L elements
            int res = INT_MIN;
            for(int i = L; i + M <= n; i++) {
                int sumM = pre[i+M] - pre[i];      // current M-length window
                res = max(res, maxL + sumM);      // combine with best L-window before it
                maxL = max(maxL, pre[i+1] - pre[i+1-L]); // update best L-window ending at i
            }
            return res;
        };

        // Try both orders
        return max(maxSum(firstLen, secondLen), maxSum(secondLen, firstLen));
    }
};
