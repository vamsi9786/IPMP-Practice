// k-3 ones
//then k==3 case               

#include <stdio.h>
typedef long long ll;
int main(){
     int t;
     scanf("%d",&t);
     while(t--){
          ll n,k;
          scanf("%lld %lld",&n,&k);
          
          for(int i=0;i<k-3;i++){
               printf("%d ",1);
          }
          ll m=n-(k-3);
          if(m%2==1){
               printf("1 %lld %lld\n",(m-1)/2,(m-1)/2);
          }
          else{
               if(m%4==0){
                    printf("%lld %lld %lld\n",m/2,m/4,m/4);
               }
               else{
                    printf("2 %lld %lld\n",(m-2)/2,(m-2)/2);
               }
          }
     }
}
