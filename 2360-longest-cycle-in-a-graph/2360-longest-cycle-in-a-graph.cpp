class Solution {
    private:
    bool dfs(int node , vector<vector<int>> & adj,vector<int>& vis){
        vis[node]=2;
       for(auto it : adj[node]){
           if(!vis[it]){
               if(dfs(it,adj,vis)) return true;
           }
           else if(vis[it] == 2) return true;
       }
       vis[node]=1;
       return false;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        //READ HTHE CONSTRAINT BUDDY GIVEN START AS -1 OF EDGES[I] SKIP THIS ONE USING CONTINUE
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(edges[i] ==-1) continue;
            adj[edges[i]].push_back(i);
        }
        int maxi = -1;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool check = dfs(i,adj,vis);
                  if(check)
            {
                int cnt=1;
                int curr=i;
                while(i!=edges[curr])curr=edges[curr],cnt++;
                
                maxi=max(maxi,cnt);
            }
            }
        }
        return maxi;
    }
};