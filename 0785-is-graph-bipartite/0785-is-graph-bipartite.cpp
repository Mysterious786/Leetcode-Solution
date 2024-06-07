class Solution {
    vector<int> color;
    private:
    bool dfs(int node,int col,vector<vector<int>>& g){
        color[node] = col;
        for(auto it : g[node]){
            if(color[it]==-1){
                if(dfs(it,!col,g)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        color.resize(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph)==false) return false;
            }
        }
        return true;
    }
};