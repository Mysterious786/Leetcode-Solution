class Solution {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({ 0, { 0, 0 } });
        dis[0][0] = 0;

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();
            int d = q.first;
            int row = q.second.first;
            int col = q.second.second;

            // if (row == n - 1 && col == m - 1) {
            //     return d;
            // }

            for (int i = 0; i < 4; i++) {
                int newRow = dx[i] + row;
                int newCol = dy[i] + col;
                if (newRow < 0 || newCol < 0 || newCol >= m || newRow >= n) continue;
                
                int diff = abs(grid[row][col] - grid[newRow][newCol]);
                int maxi = max(d, diff);
                
                if (maxi < dis[newRow][newCol]) {
                    pq.push({ maxi, { newRow, newCol } });
                    dis[newRow][newCol] = maxi;
                }
            }
        }

        return dis[n-1][m-1]; // This line is never reached as the grid is guaranteed to have at least one path
    }
};
