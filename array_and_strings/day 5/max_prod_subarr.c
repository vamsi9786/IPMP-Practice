#include <limits.h>
// O(n)

int maxProduct(int* nums, int numsSize) {
    int maxprod=nums[0];
    int minprod=nums[0]; // taking minprod bcoz of negative nos
    int ans=nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i]<0){ //swap max and min prod if (ele < 0)
            int temp=maxprod;
            maxprod=minprod;
            minprod=temp;
        }
        maxprod=(nums[i]>nums[i]*maxprod)?nums[i]:nums[i]*maxprod; //maxprod of subarr ending with idx i i.e we are considering arr till idx i
        minprod=(nums[i]<nums[i]*minprod)?nums[i]:nums[i]*minprod; //minprod of subarr ending with idx i i.e we are considering arr till idx i
        ans=(ans>maxprod)?ans:maxprod;
    }
    return ans;
}

// O(n^2)
int maxProduct(int* nums, int numsSize) {
    int pm=INT_MIN;
    if(numsSize==1) return nums[0];
    for(int i=0;i<numsSize;i++){
        int prod=1;
        for(int j=i;j<numsSize;j++){
            prod=prod*nums[j];
            pm=(pm>prod)?pm:prod;
        }
    }
    return pm;
}
