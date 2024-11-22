class Solution {
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> color;

    bool dfs(int node, int col) {
        vis[node] = 1;
        color[node] = col;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (!dfs(it, col ^ 1)) return false; // Check bipartition recursively
            } else if (color[it] == color[node]) {
                return false; // Non-bipartite if adjacent nodes have the same color
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = graph; // Directly assign adjacency list
        vis.assign(n, 0); // Initialize visited array
        color.assign(n, -1); // Initialize color array

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, 0)) return false; // Start DFS with color 0
            }
        }
        return true;
    }
};
