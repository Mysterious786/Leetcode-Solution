class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);

            }
        }
        while(!q.empty())
        {
            int node =q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(topo.size()>n or topo.size()<n)
        {
            return {};
        }
        return topo;

    }
};