#include <stdio.h>

int main(){
     int t;scanf("%d",&t);
     for(int k=0;k<t;k++){
          int n;
          scanf("%d",&n);
          int arr[n],a[n];
          for(int i=0;i<n;i++){
               arr[i]=0;scanf("%d",&a[i]);
          }
          int cover=0;
          for(int i=n-1;i>=0;i--){
               if(a[i]>cover){
                    cover=a[i];
               }
               if(cover>0){
                    arr[i]=1;cover--;
               }
          }
          for(int i=0;i<n;i++) printf("%d ",arr[i]);
          printf("\n");
     }
}
