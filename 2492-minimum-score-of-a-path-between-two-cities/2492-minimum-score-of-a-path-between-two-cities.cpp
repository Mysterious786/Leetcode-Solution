class Solution {
private:
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
    int minScore(int n, vector<vector<int>>& roads) {
        vis.resize(n,0);
        vector<int> mini(n,1e9);
        adj.resize(n);
       for(auto it : roads)
       {
        int u = it[0]-1;
        int v = it[1]-1;
        int val = it[2];
        mini[u] = min(mini[u],val);
        mini[v] = min(mini[v],val);
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       dfs(0);
       int ans = 1e9;
       for(int i=0;i<n;i++)
       {
        if(vis[i])
        {
            ans = min(ans,mini[i]);
        }
       }
       return ans;
    }
};