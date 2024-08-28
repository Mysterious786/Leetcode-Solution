class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create a priority queue with custom comparator for min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize distance array with INT_MAX
        vector<int> dist(n + 1, INT_MAX);

        // Build adjacency list representation
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back(make_pair(it[2], it[1])); // (weight, destination)
        }

        // Start exploration from node k
        pq.push({0, k}); // (distance, node)
        dist[k] = 0;

        // Dijkstra's algorithm loop
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first; // Current distance from source
            int node = top.second; // Current node

            // Explore neighbors
            for (auto it : adj[node]) {
                int neighbor = it.second; // Destination node
                int weight = it.first;   // Edge weight

                // Update distance if shorter path found
                if (dist[neighbor] > dist[node] + weight) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Check for unreachable nodes
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // Unreachable node found
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};