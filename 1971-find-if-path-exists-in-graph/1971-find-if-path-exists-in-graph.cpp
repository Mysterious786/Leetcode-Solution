class Solution {
    vector<vector<int>> adj;
    vector<int> vis;
    void dfs(int node)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it);
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.clear();
        adj.resize(n+1);
        vis.clear();
        vis.resize(n+1,0);
        for(auto it : edges)
        {
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        dfs(source);
        return (vis[source] and (vis[destination]));
    }
};