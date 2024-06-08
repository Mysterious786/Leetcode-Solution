class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, 1e9); // Initialize distances to a high value
        vector<vector<pair<int, int>>> adj(n);
        for (auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]}); // Adjust to zero-based indexing
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1}); // Adjust source node to zero-based indexing
        dis[k - 1] = 0; // Distance to the source node is 0

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();
            int node = q.second;
            int d = q.first;

            for (auto& it : adj[node]) {
                int to = it.first;
                int weight = d + it.second;
                if (weight < dis[to]) { // Relaxation step
                    dis[to] = weight;
                    pq.push({weight, to});
                }
            }
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (dis[i] == 1e9) return -1; // If any node is unreachable, return -1
            maxi = max(dis[i], maxi);
        }
        return maxi;
    }
};
