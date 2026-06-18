https://www.codechef.com/SNCKPE19/problems/BUDDYNIM

Alice, Bob and Charlie are playing a new game called Buddy NIM. The game is played at two tables; on the first table, there are 
N N heaps containing A1,A2,…,AN    A1,A2,…,AN stones and on the second table, there are M
M heaps containing B1,B2,…,BM  B1,B2,…,BM stones respectively.

Initially, Alice is playing at the first table and Bob is playing at the second table. The players take their turns in this order: Charlie, Alice, Bob, Charlie, etc.
Alice and Bob follow the rules for classical NIM - on Alice's turn, Alice must remove a positive number of stones from one of the piles at her current table and
on Bob's turn,Bob must remove a positive number of stones from one of the piles at his current table. Whoever cannot remove any stone from a pile loses.
Charlie does not play at any table. Instead, on his turn, he decides if Alice and Bob should keep playing at their respective tables or swap places.

sol:
    Charlie moves BEFORE every Alice-Bob round. He can always decide: Alice continues OR Alice swaps.
Algo:
      if(A==B)
      Every move Alice makes,Bob can mirror.Charlie cannot create an imbalance because both tables are identical.
      Eventually, Alice runs out first.Bob wins.

      if(A!=B)
      Charlie always swaps cleverly.Alice always gets the favorable table.Bob cannot mirror.Alice wins.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int n,m;
        cin>>n>>m;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x>0) a.push_back(x);
        }
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(x>0) b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        if(a==b) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}
