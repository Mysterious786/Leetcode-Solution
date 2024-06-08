#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    const static long long MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> dis(n, {1e18, 0}); // {shortest distance, number of ways}
        dis[0] = {0, 1}; // starting node with distance 0 and 1 way to reach
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]}); // because the roads are bidirectional
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
  
        while (!pq.empty()) {
            auto it = pq.top();
            long long edge = it.first;
            int node = it.second;
            pq.pop();
            
           // if (edge > dis[node].first) continue; // Skip if we have already found a shorter way
            
            for (auto& adjNode : adj[node]) {
                int to = adjNode.first;
                int W = adjNode.second;
                if (dis[to].first > edge + W) {
                    dis[to].first = edge + W;
                    dis[to].second = dis[node].second;
                    pq.push({dis[to].first, to});
                } else if (dis[to].first == edge + W) {
                    dis[to].second = (dis[to].second + dis[node].second) % MOD;
                }
            }
        }
        
        return dis[n - 1].second;
    }
};
