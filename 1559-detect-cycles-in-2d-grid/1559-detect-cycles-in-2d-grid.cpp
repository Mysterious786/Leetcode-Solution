class Solution {
public:
    bool dfs(int row, int col, int parentRow, int parentCol, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            
            // Check boundary conditions and matching character
            if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m || grid[newRow][newCol] != grid[row][col]) {
                continue;
            }

            // If the cell is already visited
            if (vis[newRow][newCol]) {
                // Check if it is not the parent cell
                if (newRow != parentRow || newCol != parentCol) {
                    return true;
                }
            } else {
                // Recurse into the next cell
                if (dfs(newRow, newCol, row, col, grid, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
