class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m) {
        // Out of range or already visited or not 'O'
        if (row < 0 || row >= n || col < 0 || col >= m || vis[row][col] == 1 || board[row][col] != 'O') {
            return;
        }
        vis[row][col] = 1;  // Mark as visited
        for (int i = 0; i < 4; i++) {
            int newRow = dx[i] + row;
            int newCol = dy[i] + col;
            // Only proceed if within bounds and not visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == 0 && board[newRow][newCol] == 'O') {
                dfs(newRow, newCol, board, vis, n, m);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;  // Empty board
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Start DFS from 'O's on the border
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, board, vis, n, m);
            }
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                dfs(n - 1, i, board, vis, n, m);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, board, vis, n, m);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, board, vis, n, m);
        }}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O') board[i][j] ='X';
            }
        }
        
        
        
        
    }
};