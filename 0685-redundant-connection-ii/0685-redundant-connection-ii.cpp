class Solution {
private:
    class DisjointSet {
        vector<int> rank, parent;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        bool unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return false; // Cycle detected
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
            return true;
        }
    };

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1, 0);   // Track parents of each node
        vector<int> can1 = {-1, -1};     // First candidate edge in case of two parents
        vector<int> can2 = {-1, -1};     // Second candidate edge in case of two parents
        
        // Step 1: Find if a node has two parents
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (parents[v] == 0) {
                parents[v] = u;
            } else {
                can2 = {u, v};           // Store second edge
                can1 = {parents[v], v};   // Store first edge
                edges[i][1] = 0;          // Mark this edge for skipping later
            }
        }

        // Step 2: Union-Find to detect a cycle
        DisjointSet dsu(n);
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;   // Skip the invalid edge
            if (!dsu.unionByRank(edge[0], edge[1])) {
                // Cycle detected
                if (can1[0] != -1) return can1; // If a node has two parents, return the first edge
                return edge;                     // Otherwise, return the edge that caused the cycle
            }
        }

        // Step 3: If no cycle detected, return the second parent edge
        return can2;
    }
};
