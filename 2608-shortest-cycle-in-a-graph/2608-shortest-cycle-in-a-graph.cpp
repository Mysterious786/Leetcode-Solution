class Solution {
public:
    vector<vector<int>> adj;
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            queue<pair<int, int>> q;
            q.push({i, -1});
            dist[i] = 0;
            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();
                for (auto neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push({neighbor, node});
                    } else if (neighbor != parent) {
                        ans = min(ans, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
