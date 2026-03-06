//max prefix sum is max sum from 0 idx to some idx
//max suffix sum is max sum from last idx to some idx
//as in concatenation may start from middle of array
//if array_sum>0   res= pre_sum+ ((k-2)*arr_sum) + suff_sum       else res=pre_sum+suff_sum
//finally check if single arr sum > res or not

#include <stdio.h>
#include <limits.h>
long long kadane(int* arr,int n){
    long long ms=arr[0],cs=arr[0];
    for(int i=1;i<n;i++){
        cs=(cs+arr[i]>arr[i])?cs+arr[i]:arr[i];
        if(cs>ms) ms=cs;
    }
    return ms;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++){
        int n,k;
        long long sum_a=0;
        scanf("%d %d",&n,&k);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum_a+=a[i];
        }
        long long kad1=kadane(a,n);
        if(k==1){
            printf("%lld\n",kad1);
            continue;
        }
        
        long long prefix = 0,max_prefix = LLONG_MIN;
        for(int i=0;i<n;i++){
            prefix += a[i];
            if(prefix > max_prefix) max_prefix = prefix;
        }
        
        long long suffix = 0, max_suffix = LLONG_MIN;
        for(int i=n-1;i>=0;i--){
            suffix += a[i];
            if(suffix > max_suffix) max_suffix = suffix;
        }
        
        long long res=max_suffix+max_prefix;
        if(sum_a >0) res+=sum_a*(k-2);
        if(res < kad1) res = kad1;

        printf("%lld\n",res);
    }
}


