class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // number of nodes
        vector<int> vis(n, 0); // visited array of size n
        int count = 0;
        vector<vector<int>> adj(n); // adjacency list of size n

        // Constructing adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Perform DFS for each component
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};
