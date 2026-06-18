For an array a of integers let's denote its maximal element as max(a), and minimal as min(a). 
We will call an array a of k integers interesting if max(a)−min(a)≥k. 
For example, array [1,3,4,3] isn't interesting as max(a)−min(a)=4−1=3<4 while array [7,3,0,4,3] is as max(a)−min(a)=7−0=7≥5.

You are given an array a of n integers. Find some interesting nonempty subarray of a, or tell that it doesn't exist.
An array b is a subarray of an array a if b can be obtained from a by deletion of several (possibly, zero or all) 
elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.

Output
For each test case, output "NO" in a separate line if there is no interesting nonempty subarray in a.
Otherwise, output "YES" in a separate line. In the next line, output two integers l and r (1≤l≤r≤n) — 
bounds of the chosen subarray. If there are multiple answers, print any.

#include <bits/stdc++.h>
using namespace std;

int main(){
     int tc;
     cin>>tc;
     for(int t=0;t<tc;t++){
          int n;
          cin>>n;
          vector<int> arr(n);
          for(int i=0;i<n;i++) cin>>arr[i];
          int f=1;
          for(int i=0;i<n-1;i++){
              if(abs(arr[i]-arr[i+1])>=2){
                  cout<<"YES\n";
                  cout<<i+1<<" "<<i+2<<"\n";
                  f=0;
                  break;
              }
          }
          if(f) cout<<"NO\n";
     }
}
