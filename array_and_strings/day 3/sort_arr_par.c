int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int* arr=malloc(sizeof(int)*numsSize);
    int l=0,r=numsSize-1;
    for(int i=0;i<numsSize;i++){
        if(nums[i]%2==0){
            arr[l++]=nums[i];
        }
        else{
            arr[r--]=nums[i];
        }
    }
    return arr;
}
