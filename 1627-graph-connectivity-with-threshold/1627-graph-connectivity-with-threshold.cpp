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
private:
    vector<int> findDiv(int n) {
        vector<int> ans;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) 
                    ans.push_back(i);
                else {
                    ans.push_back(i);
                    ans.push_back(n / i);
                }
            }
        }
        return ans;
    }
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSet dsu(n + 1);
        
        for (int i = threshold + 1; i <= n; i++) {
            vector<int> v = findDiv(i);
            for (auto it : v) {
                if (it > threshold) {
                    dsu.unionBySize(it, i);
                }
            }
        }

        vector<bool> ans;
        for (auto it : queries) {
            int u = it[0];
            int v = it[1];
            if (dsu.findUPar(u) == dsu.findUPar(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
