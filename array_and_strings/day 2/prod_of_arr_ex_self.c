int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int* a=malloc(sizeof(int)*numsSize);
    a[0]=1;
    for(int i=1;i<numsSize;i++){
        a[i]=a[i-1]*nums[i-1];
    }
    int right=1;
    for(int i=numsSize-1;i>=0;i--){
        a[i] *=right;
        right *=nums[i];
    }
    return a;
}
