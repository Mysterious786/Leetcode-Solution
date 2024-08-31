#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n, 0);

        // Initialize the dp array with default distances
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 1;
        }

        vector<int> ans;
        vector<vector<int>> roads(n); // Correctly declare roads as a vector of vectors

        // Process each query
        for (auto& it : queries) {
            int u = it[0];
            int v = it[1];

            roads[v].push_back(u); // Push the road connection

            for (int i = v; i < n; i++) {
                dp[i] = min(dp[i], dp[i - 1] + 1);

                for (auto& connectedNode : roads[i]) {
                    dp[i] = min(dp[i], dp[connectedNode] + 1);
                }
            }

            ans.push_back(dp[n - 1]); // Store the shortest distance to the last node
        }

        return ans;
    }
};
