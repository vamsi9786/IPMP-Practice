int maxSubArray(int* nums, int numsSize) {
    int ms=nums[0],cs=nums[0];
    for(int i=1;i<numsSize;i++){
        cs=(cs+nums[i]>nums[i])?cs+nums[i]:nums[i];
        if(cs>ms) ms=cs;
    }
    return ms;
}
