.Optimal approach O(n) HASH TABLE

typedef long long ll;

int firstMissingPositive(int* nums, int numsSize) {
    //i+1 should be at ith place
    int i=0;
    while(i<numsSize){
        if(nums[i]!=i+1 && nums[i]<=numsSize && nums[i]>=1 && nums[nums[i]-1]!=nums[i]){
            int temp=nums[i];
            nums[i]=nums[temp-1];
            nums[temp-1]=temp;
        }
        else{
            i++;
        }
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=i+1) return i+1;
    }

    return numsSize+1;
}


/Not optimal approach O(nlogn)

typedef long long ll;
int cmp(const void* a,const void* b){
    int x=*(const int*)a;
    int y=*(const int*)b;
    if(x < y){
        return -1;
    }
    else if(x > y){
        return 1;
    }
    else return 0;
}

int firstMissingPositive(int* nums, int numsSize) {
    ll ans=1;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(ll i=0;i<numsSize;i++){
        if(nums[i]>0 && ans==nums[i]){
            ans++;
        }
    }
    return ans;
}
