#include <stdio.h>

typedef long long ll;

int main(){
     int t;
     scanf("%d",&t);
     while(t--){
          ll n,k;
          scanf("%lld %lld",&n,&k);
          if(n%2==1){
               printf("1 %lld %lld\n",(n-1)/2,(n-1)/2);
          }
          else{
               if(n%4==0) printf("%lld %lld %lld\n",n/2,n/4,n/4);
               else{
                    printf("2 %lld %lld\n",(n-2)/2,(n-2)/2);
               }
          }
     }
}
