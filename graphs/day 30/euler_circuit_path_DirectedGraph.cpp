Euler Circuit and Path for directed graph

1. Euler Path:

bool hasEulerPath(int V, vector<vector<int>>& edges) {

    vector<vector<int>> adj(V);

    vector<int> indegree(V,0);
    vector<int> outdegree(V,0);

    for(auto &e:edges){

        int u=e[0];
        int v=e[1];

        adj[u].push_back(v);

        outdegree[u]++;
        indegree[v]++;
    }

    int start=0,end=0;

    for(int i=0;i<V;i++){

        if(outdegree[i]-indegree[i]==1)
            start++;

        else if(indegree[i]-outdegree[i]==1)
            end++;

        else if(indegree[i]!=outdegree[i])
            return false;
    }

    return (start==1 && end==1) ||
           (start==0 && end==0);
}

2. Euler Circuit:

bool hasEulerCircuit(int V, vector<vector<int>>& edges){

    vector<int> indegree(V,0);
    vector<int> outdegree(V,0);

    for(auto &e:edges){

        outdegree[e[0]]++;
        indegree[e[1]]++;
    }

    for(int i=0;i<V;i++){

        if(indegree[i]!=outdegree[i])
            return false;
    }

    return true;
}
