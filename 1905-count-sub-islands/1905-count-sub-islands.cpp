class Solution {
   int dx[4] = {-1, 1, 0, 0}; 
   int dy[4] = {0, 0, 1, -1};

private:
    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int n, int m, bool& yes) {
        // First check if we're out of bounds or the cell is already visited
        if (row < 0 or row >= n or col < 0 or col >= m or vis[row][col] == 1 or grid2[row][col]==0) 
            return;
        
        // If grid2 has land but grid1 doesn't, then this can't be a sub-island
        if (grid1[row][col] == 0 and grid2[row][col] == 1) 
            yes = false;
        
        // Mark the cell as visited
        vis[row][col] = 1;
        
        // Explore the four possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            dfs(newRow, newCol, grid1, grid2, vis, n, m, yes);
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        // Traverse the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // Only start DFS if grid2 has land and it hasn't been visited yet
                if (grid2[row][col] == 1 && !vis[row][col]) {
                    bool yes = true;
                    dfs(row, col, grid1, grid2, vis, n, m, yes);
                    if (yes) ans++;
                }
            }
        }
        return ans;
    }
};
