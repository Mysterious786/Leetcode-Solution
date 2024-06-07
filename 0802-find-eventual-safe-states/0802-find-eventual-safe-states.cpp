class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0); // Initialize ind with size n and all elements as 0

        // Reverse the graph and calculate in-degrees
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                ind[i]++;
            }
        }

        queue<int> q;
        // Add all nodes with in-degree 0 to the queue
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                ind[it]--;
                if (ind[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
