#include <stdio.h>
#include <math.h>
#include <limits.h>

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

int nextGreaterElement(int n) {
    int d=0,x=n,i=0,dig[12];
    long long res=0;
    if(n>=0 && n<10) return -1;
    else if(n>=10 && n<100){
        int d1,d2,y=n;
        d2=n%10;n=n/10;
        d1=n%10;
        res=d2*10+d1;
        if(res<=y) return -1;
        return res;
    }
    while(x>0){
        i++;x=x/10;
    }
    x=n;
    for(int j=i-1;j>=0;j--){
        dig[j]=x%10;
        x=x/10;
    }
    x=n;
    int k=i-2,f=0;
    while(k>=0 && dig[k]>=dig[k+1]) k--;
    if(k>=0){
        int l=i-1;
        while(dig[l]<=dig[k]) l--;
        int temp=dig[k];
        dig[k]=dig[l];
        dig[l]=temp;
        qsort(dig+k+1,i-k-1,sizeof(int),cmp);
        f=1;
    }
    if(f==0) qsort(dig,i,sizeof(int),cmp);
    for(int j=0;j<i;j++){
        res=res*10+dig[j];
        if(res>INT_MAX) return -1;
    }
    x=n;
    if(res<=n) return -1;
    else return (int)res;
}
