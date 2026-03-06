#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
     return *(int*)a - *(int*)b;
}

int main(){
     int tc;
     scanf("%d",&tc);
     for(int t=0;t<tc;t++){
          int n,c=0;
          scanf("%d",&n);
          int a[n],b[n],k=0,x=0;
          for(int i=0;i<n;i++) scanf("%d",&a[i]);
          qsort(a,n,sizeof(int),cmp);
          for(int i=0;i<n;i++){
               if(i==0 || a[i-1]!=a[i]) a[k++]=a[i];
               else b[x++]=a[i];
               
          }
          for(int i=0;i<x;i++){
               a[k+i]=b[i];
          }
          for(int i=0;i<n;i++) printf("%d ",a[i]);
          printf("\n");
     }
}
