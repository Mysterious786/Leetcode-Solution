class Solution {
    map<int,int> mp;
    private:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node] = 1;
        if(mp.find(node)==mp.end()) return;
        for(auto it : adj[node]){
            if(vis[it]==0){
                mp[it]++;
                dfs(it,vis,adj);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adj(rooms.size());
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> vis(rooms.size());
        mp[0]++;
        int n = rooms.size();
        for(int i=0;i<n;i++){
            if(vis[i]==0) dfs(i,vis,adj);
        }
        for(int i=0;i<rooms.size();i++){
            if(mp.find(i)==mp.end()) return false;
        }
        return true;
    }
};