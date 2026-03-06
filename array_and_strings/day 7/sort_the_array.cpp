#include <bits/stdc++.h>
using namespace std;
int main(){
     int n;
     cin>>n;
     vector<long long> arr(n);
     vector<long long> res(n);
     for(int i=0;i<n;i++){
          cin>>arr[i];
          res[i]=arr[i];
     }
     sort(res.begin(),res.end());
     int l=-1,r=-1;
     for(int i=0;i<n;i++){
          if(res[i]!=arr[i]){
               l=i;
               break;
          }
     }
     if(l==-1){
          cout<<"yes"<<endl;
          cout<<1<<" "<<1<<endl;
          return 0;
     }
     for(int i=n-1;i>=0;i--){
          if(res[i]!=arr[i]){
               r=i;
               break;
          }
     }
     reverse(arr.begin()+l,arr.begin()+r+1);
     if(arr==res){
          cout<<"yes"<<endl;
          cout<<l+1<<" "<<r+1<<endl;
     }
     else{
          cout<<"no"<<endl;
     }
}
