int dominantIndex(int* nums, int numsSize) {
    int l=0,r=numsSize-1,me=0,mi=-1;
    while(l<=r){
        if(nums[l]>me){
            me=nums[l];mi=l;
        }
        if(nums[r]>me){
            me=nums[r];mi=r;
        }
        l++;r--;
    }
    l=0;r=numsSize-1;
    while(l<=r){
        if(l!=mi && 2*nums[l]>me) return -1;
        if(r!=mi && 2*nums[r]>me) return -1;
        l++;r--; 
    }
    return mi;
}
