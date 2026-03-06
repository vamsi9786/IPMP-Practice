int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int l=numsSize/2,i=0,me=nums[0];
    if(numsSize==1) return nums[0];
    while(i<numsSize){
        if(i+l<numsSize && nums[i]==nums[i+l]){
            me=nums[i];
            i=i+l;
        }
        else{
            i++;
        }
    }
    return me;
}
