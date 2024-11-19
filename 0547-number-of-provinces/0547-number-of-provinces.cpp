class Solution {
    vector<int> vis;
    vector<vector<int>> adj;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        vis.clear();
        adj.clear();
        int n = isConnected.size();
        vis.resize(n,0);
        adj.resize(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int province = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                province++;
            }
        }
        return province;
    }
};