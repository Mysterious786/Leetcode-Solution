class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, 1e9);
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});
        dis[src] = 0;

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();
            int stop = q.first;
            int from = q.second.first;
            int val = q.second.second;

            if (stop > k) continue;

            for (auto& it : adj[from]) {
                int to = it.first;
                int edgeWeight = it.second;
                int newWeight = edgeWeight + val;
                
                if (newWeight < dis[to] && stop <= k) {
                    dis[to] = newWeight;
                    pq.push({stop + 1, {to, newWeight}});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};