class Solution {
    vector<int> vis;
    vector<vector<int>> adj;
    int edges,vertex;
    void dfs(int node)
    {
        vis[node] = 1;
        vertex++;
        edges+=adj[node].size();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.clear();
        vis.clear();
        vis.resize(n,0);
        adj.resize(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
             this->edges = 0;
             this->vertex = 0;
            if(!vis[i])
            {
                dfs(i);
                if(this->edges == this->vertex*(this->vertex-1))
                {
                    ans = ans+1;
                }
            }
        }
        return ans;
    }
};