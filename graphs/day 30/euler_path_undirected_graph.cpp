
Euler's Theorem (Undirected Graph)

An undirected graph has an Eulerian Path if and only if:
    1. All vertices having non-zero degree belong to one connected component.
    2. The number of vertices with odd degree is either:
              0 → Eulerian Cycle (which is also an Eulerian Path)
              2 → Eulerian Path
              More than 2 → Not possible

Why only 0 or 2 odd-degree vertices?
            1. Suppose we walk through every edge exactly once.
            2. For every intermediate vertex:
                  We enter through one edge.
                  We leave through another edge.
            3. So edges are used in pairs.
Therefore, intermediate vertices must have even degree.


class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int next : adj[node]) {
            if (!vis[next])
                dfs(next, adj, vis);
        }
    }

    bool hasEulerPath(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);

        // Find a vertex with non-zero degree
        int start = -1;

        for (int i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                start = i;
                break;
            }
        }

        // No edges in the graph
        if (start == -1)
            return true;

        dfs(start, adj, vis);

        // Check connectivity of non-zero degree vertices
        for (int i = 0; i < V; i++) {
            if (!adj[i].empty() && !vis[i])
                return false;
        }

        // Count odd-degree vertices
        int odd = 0;

        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2)
                odd++;
        }

        return (odd == 0 || odd == 2);
    }
};
