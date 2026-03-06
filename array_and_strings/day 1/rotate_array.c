void rotate(int* nums, int numsSize, int k) {
    int temp[k+1],x=0;
    k=k%numsSize;
    int* t2=malloc(sizeof(int)*numsSize);
    for(int i=numsSize-k;i<numsSize;i++){
        temp[x++]=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        if(i<k) t2[i]=temp[i];
        else t2[i]=nums[i-k];
    }
    for(int i=0;i<numsSize;i++){
        nums[i]=t2[i];
    }
}
