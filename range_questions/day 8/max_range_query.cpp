Algo:
  1. using prefix sum find the final cakes after all operations.
  2. find the height of each cake and also no of cakes with exactly k height. (count )
  3. After removing an operation 
        (i) height with k decreases to k-1
        (ii) height with k+1 decreases to k
      so find gain in height k i.e gain= ((from k+1 to k) - (from k to k-1))
      so find max of gains.
  4. return res=count+max_gain.


#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int n,k;
        int st,en;
        cin>>n>>k;
        vector<pair<int,int>> a(n);
        vector<int> ans(100002,0);
        for(int i=0;i<n;i++){
            cin>>st>>en;
            a[i]={st,en};
            ans[st]+=1;
            ans[en+1]-=1;
        }
        vector<int> H(100001,0);
        for(int i=1;i<=100000;i++){
            H[i]=H[i-1]+ans[i];
        }
        int res=0;
        for(int i=1;i<=100000;i++){
            if(H[i]==k) res++;
        }
        
        vector<int> p1(100001,0),p2(100001,0);
        for(int i=1;i<=100000;i++){
            p1[i]=p1[i-1]+(H[i]==k);      (Represents prefix sum till cake i i.e prefix sum of no of cakes with height exactly 'k' untill cake i)
            p2[i]=p2[i-1]+(H[i]==k+1);    (Represents prefix sum till cake i i.e prefix sum of no of cakes with height exactly 'k+1' untill cake i)
        }
        
        int mxgain=INT_MIN;
        for(auto &x:a ){
            int L=x.first;
            int R=x.second;
            
            int k1=p1[R]-p1[L-1];  (diff b/w prefix sums of R and L i.e no of cakes with height exactly 'k' in between [L,R] )
            int k2=p2[R]-p2[L-1];  (diff b/w prefix sums of R and L i.e no of cakes with height exactly 'k+1' in between [L,R] )
            int gain=k2-k1;
            mxgain=max(mxgain,gain);
        }
        
        cout<<res+mxgain<<endl;
    }
}
