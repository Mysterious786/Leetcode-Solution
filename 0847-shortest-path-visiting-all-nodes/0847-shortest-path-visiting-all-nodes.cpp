class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1<<n) - 1;
        vector<vector<int>> vis(n,vector<int>(mask+1,0));
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            q.push({{i,(1<<i)},0});
            vis[i][1<<i] = 1;
        }
        while(!q.empty())
        {
            auto front = q.front();
            int node = front.first.first;
            int currentMask = front.first.second;
            int steps = front.second;
            q.pop();
            if(currentMask == mask)
            {
                return steps;
            }
            for (int neighbor : graph[node]) {
                int newMask = currentMask | (1 << neighbor);
                if (!vis[neighbor][newMask]) {
                    vis[neighbor][newMask] = 1;
                    q.push({{neighbor,newMask},steps + 1});
                }
            }
        }
        return -1;
    }
};