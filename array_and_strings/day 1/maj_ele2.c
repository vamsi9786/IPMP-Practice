int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int* a=malloc(sizeof(int)*numsSize);
    int x=0,l=numsSize/3;
    if(numsSize==1){
        a[x++]=nums[0];
    }
    else if(numsSize==2){
        if(nums[0]==nums[1]){
            a[x++]=nums[0];
        }
        else{
            a[x++]=nums[0];a[x++]=nums[1];
        }
    }
    else{
        int i=0;
        while(i<numsSize){
            if(i+l<numsSize && nums[i]==nums[i+l]){
                a[x++]=nums[i];
                int e=nums[i];
                while(i<numsSize &&nums[i]==e) i++;
            }
            else i++;
        }
    }
    *returnSize=x;
    return a;
}
