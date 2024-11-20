class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : redEdges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,0});
        }
        for(auto it : blueEdges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,1});
        }
        vector<vector<int>> dist(n,vector<int>(2,1e9));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,-1},0});
        dist[0][1] = dist[0][0] =  0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first.first;
            int color = it.first.second;
            int distance = it.second;
            for(auto it : adj[node])
            {
                int newColor = it.second;
                int to = it.first;
                if(newColor == color) continue;
                if(dist[to][newColor] > distance + 1)
                {
                    dist[to][newColor] = distance + 1;
                    q.push({{to,newColor},dist[to][newColor]});
                }
            }
        }
        vector<int> res(n,-1);
        for(int i =0;i<n;i++)
        {
            int ans = min(dist[i][1],dist[i][0]);
            if(ans == 1e9) continue;
            else res[i] = ans;
        }
        return res;
    }
};