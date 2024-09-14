class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        // Helper function for DFS with memoization
        function<int(int, int)> dfs = [&](int row, int col) {
            if (dp[row][col] != -1) return dp[row][col];

            int pathCount = 1; // Each cell itself is a valid path
            for (int i = 0; i < 4; ++i) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] > grid[row][col]) {
                    pathCount = (pathCount + dfs(newRow, newCol)) % MOD;
                }
            }
            dp[row][col] = pathCount;
            return pathCount;
        };

        int totalPaths = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                totalPaths = (totalPaths + dfs(row, col)) % MOD;
            }
        }
        return totalPaths;
    }
};
