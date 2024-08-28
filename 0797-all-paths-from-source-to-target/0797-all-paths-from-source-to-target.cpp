#include <vector>

class Solution {
    vector<vector<int>> ans;
    vector<int> currentPath;

    void dfs(int node, int dest, vector<vector<int>>& graph) {
        currentPath.push_back(node);
        
        if (node == dest) {
            ans.push_back(currentPath);
        } else {
            for (auto it : graph[node]) {
                dfs(it, dest, graph);
            }
        }
        
        currentPath.pop_back(); // Backtrack
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(0, n - 1, graph);
        return ans;
    }
};
