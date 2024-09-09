class Solution {
private:
    void dfs(int node,vector<int>& vis,vector<int>& color,vector<vector<int>>& adj){
        vis[node] = 1;
        set<int> st;
        for(auto it : adj[node]){
            st.insert(color[it]);
        }
        for(int i=1;i<=4;i++){
            if(st.find(i)==st.end()){
                color[node] = i;
                break;
            }
        }
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,color,adj);
            }
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        for(auto it : paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,color,adj);
            }
        }
        return color;
    }
};