int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* arr=malloc(numsSize*sizeof(int));
    int left=0,right=numsSize-1;
    while(left<=right){
        arr[left]=nums[left]*nums[left];
        if(left!=right) arr[right]=nums[right]*nums[right];
        left++;right--;
    }
    *returnSize=numsSize;
    qsort(arr,numsSize,sizeof(int),cmp);
    return arr;
}
