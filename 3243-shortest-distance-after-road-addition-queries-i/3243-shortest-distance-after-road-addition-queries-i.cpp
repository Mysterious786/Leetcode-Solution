#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
private:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S)
    {
        // Create a priority queue for storing nodes as a pair {dist,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initializing distTo list with a large number (indicating infinity)
        vector<int> distTo(V, INT_MAX);

        // Source initialized with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Process nodes in the priority queue
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check all adjacent nodes of the popped node
            for (auto& it : adj[node])
            {
                int v = it.first;
                int w = it.second;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;

                    // Push the updated distance to the queue
                    pq.push({distTo[v], v});
                }
            }
        }

        // Return the list containing the shortest distances from source to all nodes.
        return distTo;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Initialize the adjacency list
        vector<vector<pair<int, int>>> adj(n);

        // Create the initial graph connections
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back({i + 1, 1});
            //adj[i + 1].push_back({i, 1});
        }

        vector<int> ans;
        for (auto& it : queries) {
            int u = it[0];
            int v = it[1];

            // Add the bidirectional edges for each query
            adj[u].push_back({v, 1});
           // adj[v].push_back({u, 1});

            // Get the shortest distances from node 0
            vector<int> dist = dijkstra(n, adj, 0);

            // Assuming you want the distance to the node `v`
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};

