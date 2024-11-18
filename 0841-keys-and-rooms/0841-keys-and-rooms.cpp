class Solution {
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.clear();
        adj.clear();
        vis.resize(n, 0);
        adj.resize(n);
        
        // Construct adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                adj[i].push_back(rooms[i][j]);
            }
        }

        // Perform DFS from room 0
        dfs(0);

        // Check if all rooms are visited
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
};
