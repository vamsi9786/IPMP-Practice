int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right) {
    /*int me=0,c=0,si=0,k=0;
    while(si+k<numsSize){
        me=(me>nums[si+k])?me:nums[si+k];
        if(me>=left && me<=right){
            k++;
            c++;
        }
        else if(me<left){
            k++;
        }
        else{
            si++;
            k=0;me=0;
        }
        if(si+k>=numsSize){
            si++;k=0;me=0;
        }
    }
    return c;*/
    
    int res = 0;
    int lastGreater = -1; 
    int lastValid = -1;
    for(int i=0;i<numsSize;i++){
        if (nums[i] > right) lastGreater = i;
        if (nums[i] >= left) lastValid = i;
        if(lastValid > lastGreater) res += lastValid - lastGreater;
    }
    return res;
}
