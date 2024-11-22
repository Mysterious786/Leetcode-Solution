class Solution {
    vector<vector<int>> adj;
    vector<int> color, vis;

    // Helper function to check if the graph is bipartite
    bool dfs(int node, int col) {
        vis[node] = 1;
        color[node] = col;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (!dfs(it, col ^ 1)) return false;
            } else if (color[it] == color[node]) {
                return false; // Conflict in coloring
            }
        }
        return true;
    }
public:
  int depthBFS(int node) {
    queue<int> q;
    vector<int> dist(adj.size(), -1); // Corrected size
    dist[node] = 0;
    q.push(node);
    int ans = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto it : adj[front]) {
            if (dist[it] == -1) { // Unvisited
                dist[it] = 1 + dist[front];
                q.push(it);
                ans = max(ans, dist[it]);
            }
        }
    }

    return ans + 1; // Return 1-based levels
}

int magnificentSets(int n, vector<vector<int>>& edges) {
    adj.clear();
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    color.assign(n + 1, -1);

    // Build adjacency list
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Check if graph is bipartite
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!dfs(i, 0)) return -1;
        }
    }

    // Reset visitation array for BFS
    vis.assign(n + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            queue<int> q;
            vector<int> component; // Track the connected component
            q.push(i);
            vis[i] = 1;

            // Perform BFS to collect all nodes in the connected component
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                component.push_back(node);

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }

            // Calculate maximum BFS depth for this component
            int maxDepth = 0;
            for (auto node : component) {
                maxDepth = max(maxDepth, depthBFS(node));
            }

            // Add the maximum depth for this component
            ans += maxDepth;
        }
    }

    return ans;
}
};