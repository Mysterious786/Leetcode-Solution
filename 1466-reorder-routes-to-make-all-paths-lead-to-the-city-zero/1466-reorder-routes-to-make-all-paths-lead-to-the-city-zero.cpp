class Solution {
    vector<vector<int>> adj;
    vector<int> vis;
    int edges;
    int dfs(int node)
    {
        vis[node] = 1;
        int ans = 0;
        for(auto it : adj[node])
        {
            if(!vis[abs(it)])
            {
                ans+=dfs(abs(it))+(it>0);
            }
        }
        return ans;

    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.clear();
        vis.clear();
        adj.resize(n);
        vis.resize(n,0);
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(-u);
        }
      return dfs(0);
        
    }
};