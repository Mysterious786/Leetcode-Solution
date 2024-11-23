class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        map<int,set<int>> mp;
        vector<vector<int>> adj(n);
        vector<int> indgree(n,0);
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indgree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indgree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                mp[it].insert(node);
                for(auto i : mp[node])
                {
                    mp[it].insert(i);
                }
                indgree[it]--;
                if(indgree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        for(auto it : mp)
        {
            vector<int> v(it.second.begin(),it.second.end());
            ans[it.first]=v;
        }
        return ans;
    }
};