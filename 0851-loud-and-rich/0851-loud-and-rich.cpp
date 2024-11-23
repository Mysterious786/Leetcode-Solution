class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto it : richer)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans(n);
        iota(ans.begin(),ans.end(),0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(quiet[node] < quiet[it])
                {
                    quiet[it] = quiet[node];
                    ans[it] = ans[node];
                }
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};