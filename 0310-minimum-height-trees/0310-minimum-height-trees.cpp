class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        if(n==1)
        {
            return {0};
        }
        for(auto it : edges)
        {
            int u = it[0];
            int v= it[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        //map<int,int> mp;
        vector<int> ans;
        while(!q.empty())
        {
            int sz = q.size();
            ans.clear();
            for(int i=0;i<sz;i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it : adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==1)
                    {
                        q.push(it);
                    }
                }
            }


        }

        return ans;

    }
};