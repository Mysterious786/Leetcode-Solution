class Solution {
    vector<vector<int>> adj;
    vector<int> color,vis;
    bool dfs(int node, int col)
    {
        vis[node] = 1;
        color[node] = col;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(!dfs(it,col^1)) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.resize(n+1,-1);
        vis.resize(n+1,0);
        adj.resize(n+1);
        for(auto it : dislikes)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = true;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ans&=dfs(i,0);
            }
        }
        return ans;
    }
};