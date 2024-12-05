class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, vector<string>> adj;
        map<string, int> indegree;
        vector<string> ans;
        map<string, int> supply;
        map<string, int> reci;

        for (auto it : recipes) reci[it]++;
        for (auto it : supplies) supply[it]++;
        
        int n = recipes.size();
        
        for (int i = 0; i < n; i++) {
            int size = ingredients[i].size();
            string current = recipes[i];
            for (int j = 0; j < size; j++) {
                string need = ingredients[i][j];
                adj[need].push_back(current);
                indegree[current]++;
            }
        }

        queue<string> q;
        
        for (auto it : supplies) {
            q.push(it);
        }

        while (!q.empty()) {
            string front = q.front();
            q.pop();

            if (reci.find(front) != reci.end()) {
                ans.push_back(front);
            }

            for (auto it : adj[front]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};
