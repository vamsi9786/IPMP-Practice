#include <stdio.h>
typedef long long ll;

int main(){
     ll l,r;
     scanf("%lld %lld",&l,&r);
     printf("YES\n");
     for(ll i=l;i<=r;i+=2){
          printf("%lld %lld\n",i,i+1);
     }
}
