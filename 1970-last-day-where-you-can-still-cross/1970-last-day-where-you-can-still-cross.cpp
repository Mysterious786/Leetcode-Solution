class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // Perform DFS to check if we can cross the grid on the given day
    bool dfs(int row, int col, int n, int m, map<pair<int, int>, int>& mp, int day, vector<vector<int>>& vis) {
        if (row == n - 1) return true; // Reached the last row
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            // Check boundaries, water conditions, and if the cell is already visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                mp[{newRow, newCol}] > day && !vis[newRow][newCol]) {
                if (dfs(newRow, newCol, n, m, mp, day, vis)) return true;
            }
        }

        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        map<pair<int, int>, int> mp;

        // Fill the map with days, converting indices from 1-based to 0-based
        for (int i = 0; i < cells.size(); i++) {
            mp[{cells[i][0] - 1, cells[i][1] - 1}] = i + 1;
        }

        int low = 1, high = cells.size(), ans = 0;

        while (low <= high) {
            int day = (low + high) / 2;
            vector<vector<int>> vis(row, vector<int>(col, 0));
            bool flag = false;

            // Try to start from any cell in the first row
            for (int i = 0; i < col; i++) {
                if (mp[{0, i}] > day && dfs(0, i, row, col, mp, day, vis)) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                ans = day;
                low = day + 1;
            } else {
                high = day - 1;
            }
        }

        return ans;
    }
};
