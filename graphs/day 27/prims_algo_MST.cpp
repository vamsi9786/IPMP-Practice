https://www.spoj.com/problems/MST/

Find the minimum spanning tree of the graph.

Input
On the first line there will be two integers N - the number of nodes and M - the number of edges. (1 ≤ N ≤ 10000, 1 ≤ M ≤ 100000)

M lines follow with three integers i j k on each line representing an edge between node i and j with weight k. 
The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be ≤ 1000000.

Output
Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.

Code:
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	//pair {wt,v}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	vector<bool> vis(n+1,false);
	
	long long mstWt=0;
	while(!pq.empty()){
		auto [ wt, u]=pq.top();
		pq.pop();
		if(vis[u]) continue;
		
		vis[u]=true;
		mstWt+=wt;
		
		for(auto [v , w ]:adj[u]){
			if(!vis[v]) pq.push({w,v});
		}
	}
	
	cout<<mstWt<<endl;
	
	return 0;
}
