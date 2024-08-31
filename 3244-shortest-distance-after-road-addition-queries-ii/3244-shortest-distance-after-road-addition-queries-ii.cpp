class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++) st.insert(i);
        for(auto it : queries){
            int u = it[0];
            int v = it[1];
            vector<int> nodes;
            auto t = st.upper_bound(u);
            while(t!=st.end() and *t < v){
                nodes.push_back(*t);
                t++;
            }
            for(auto i : nodes) st.erase(i);
                ans.push_back(st.size()-1);
        }
        return ans;
}};