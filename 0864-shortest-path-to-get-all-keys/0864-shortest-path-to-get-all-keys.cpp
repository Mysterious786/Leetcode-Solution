class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int keys = 0;
        int start = -1, end = -1;

        // Identify the starting point and count the keys
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = grid[i][j];
                if (ch == '@') {
                    start = i;
                    end = j;
                } else if (islower(ch)) {
                    keys++;
                }
            }
        }

        // All keys mask
        int mask = (1 << keys) - 1;

        // Distance array
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(mask + 1, INT_MAX)));

        // Priority queue
        priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;

        // Starting point
        dist[start][end][0] = 0;
        pq.push({{0, 0}, {start, end}});

        // Direction vectors
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // BFS with priority queue
        while (!pq.empty()) {
            auto [dist_mask, pos] = pq.top();
            int distance = dist_mask.first;
            int currentMask = dist_mask.second;
            int row = pos.first;
            int col = pos.second;
            pq.pop();

            // If all keys are collected
            if (currentMask == mask) return distance;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // Check bounds and obstacles
                if (newRow >= n || newCol >= m || newRow < 0 || newCol < 0 || grid[newRow][newCol] == '#') continue;

                char ch = grid[newRow][newCol];
                int newMask = currentMask;

                // Handle doors
                if (ch >= 'A' && ch <= 'F' && !(currentMask & (1 << (ch - 'A')))) continue;

                // Handle keys
                if (ch >= 'a' && ch <= 'f') {
                    newMask |= (1 << (ch - 'a'));
                }

                // Update distance
                if (dist[newRow][newCol][newMask] > distance + 1) {
                    dist[newRow][newCol][newMask] = distance + 1;
                    pq.push({{dist[newRow][newCol][newMask], newMask}, {newRow, newCol}});
                }
            }
        }

        return -1;
    }
};
