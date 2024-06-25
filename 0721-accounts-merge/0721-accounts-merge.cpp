class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) { 
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet dsu(n);  // Correct size initialization for DSU
        unordered_map<string, int> mp; // Use unordered_map for better performance

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {  // Start from 1 to skip the account name
                if(mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    dsu.unionBySize(i, mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> emails(n);
        for(auto& it : mp) {
            int node = it.second;
            string mail = it.first;
            int parent = dsu.findUPar(node);
            emails[parent].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(emails[i].empty()) continue;  // Skip if there are no emails
            sort(emails[i].begin(), emails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);  // Add account name
            temp.insert(temp.end(), emails[i].begin(), emails[i].end());  // Add sorted emails
            ans.push_back(temp);
        }

        return ans;
    }
};
