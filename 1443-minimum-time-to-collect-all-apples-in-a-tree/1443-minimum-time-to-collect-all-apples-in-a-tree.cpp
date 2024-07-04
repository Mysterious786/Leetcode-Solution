class Solution {
public:
    int dfs(int i, int j, vector<int> adj[], vector<bool> &hasApple) {
        int cnt=0;
        for(auto it: adj[i]) {
            if(it!=j) {
                int num=dfs(it, i, adj, hasApple);
                if(hasApple[it]){
                    num+=2; cnt+=num;
                    hasApple[i]=true;
                }
            } 
        }
        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0, 0, adj, hasApple);
    }
};