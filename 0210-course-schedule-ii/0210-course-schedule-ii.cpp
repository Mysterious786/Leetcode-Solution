class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
          vector<vector<int>> adj(n);
        for(auto it : p) adj[it[1]].push_back(it[0]);
        vector<int> ind(n,0);
        for(int i=0;i<n;i++){
            for(auto it : adj[i]) ind[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            for(auto i : adj[it]){
                ind[i]--;
                if(ind[i]==0) q.push(i);
            }
            
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};