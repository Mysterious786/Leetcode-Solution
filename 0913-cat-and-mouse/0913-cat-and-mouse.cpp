class Solution {
    vector<vector<int>> adj;
    int c = 2; // Cat wins
    int m = 1; // Mouse wins
    int d = 0; // Draw
    vector<vector<vector<int>>> dp;
    int n;

private:
    int findWinner(int turns, int mouse, int cat) {
        if (turns == 5 * n) return dp[mouse][cat][turns] = d;
        if (mouse == 0) return dp[mouse][cat][turns] = m;
        if (mouse == cat) return dp[mouse][cat][turns] = c;
        if(dp[mouse][cat][turns]!=-1) return dp[mouse][cat][turns];

        int currentTurn = turns % 2;
        if (currentTurn == 0) { // Mouse's turn
            bool drawPossible = false;
            for (auto it : adj[mouse]) {
                int ans = findWinner(turns + 1, it, cat);
                if (ans == m) return dp[mouse][cat][turns] = m;
                if (ans == d) drawPossible = true;
            }
            return dp[mouse][cat][turns] = (drawPossible ? d : c);
        } else { // Cat's turn
            bool drawPossible = false;
            for (auto it : adj[cat]) {
                if (it == 0) continue; // Cat can't move to the hole
                int ans = findWinner(turns + 1, mouse, it);
                if (ans == c) return dp[mouse][cat][turns] = c;
                if (ans == d) drawPossible = true;
            }
            return dp[mouse][cat][turns] = (drawPossible ? d : m);
        }
    }

public:
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        adj.clear();
        adj.resize(n);
        dp.clear();
        dp.resize(n, vector<vector<int>>(n, vector<int>(5 * n + 1, -1)));

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }

        return findWinner(0, 1, 2);
    }
};
