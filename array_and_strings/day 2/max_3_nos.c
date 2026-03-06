int maximumProduct(int* nums, int numsSize) {
    int m1=-1001,m2=-1001,m3=-1001;
    int mi1=1001,mi2=1001,mi3=1001;
    for(int i=0;i<numsSize;i++){
        int x=nums[i];
        if(x>m1){
            m3=m2;m2=m1;m1=x;
        }
        else if(x>m2){
            m3=m2;m2=x;
        }
        else if(x>m3){
            m3=x;
        }

        if(x<mi1){
            mi3=mi2;mi2=mi1;mi1=x;
        }
        else if(x<mi2){
            mi3=mi2;mi2=x;
        }
        else if(x<mi3){
            mi3=x;
        }
    }
    int p1=m1*m2*m3;
    int p2=mi1*mi2*m1;
    return p1>p2?p1:p2;
}
