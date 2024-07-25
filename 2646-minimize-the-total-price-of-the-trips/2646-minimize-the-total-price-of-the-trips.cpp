class Solution{
public:
    map<int,int> mp;
    vector<vector<int>> adj;
    vector<int> p;

    int dfs(int node,int par,int des){
        // base case
        if(node == des){
            mp[des]++;
            return 1;
        }

        for(auto it : adj[node]){
            if(it==par) continue;
            if(dfs(it,node,des)){
                mp[node]++;
                return 1;
            }
        }
        return 0;
    }
    pair<int,int> findPrice(int node,int par){
        int considertoHalf = mp[node]*(p[node]/2);
        int notConsiderToHalf = mp[node]*p[node];

        for(auto it : adj[node]){
            if(it==par) continue;
            pair<int,int> child = findPrice(it,node);
            //I dont half
            notConsiderToHalf += min(child.first,child.second);
            considertoHalf += child.second;
        }

        return {considertoHalf,notConsiderToHalf};

        
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips){
        //create adj list...
        //for(int i=0;i<n;i++) adj[i].clear();
        adj.resize(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // I need an array to store the occurenc of a particular node in the given trip
        for(auto it : trips){ // o(n*t)
            dfs(it[0],-1,it[1]);
        }

        // min(take the half of root, not take the half of root)...
        p = price;
        auto ans = findPrice(0,-1); //o(n)
        return min(ans.first,ans.second);

    }
};