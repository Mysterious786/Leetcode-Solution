class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int> all(n * n, -1);
        bool leftToRight = true;
        int idx = 0;
        for (int i = n - 1; i >= 0; i--) { 
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    all[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    all[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }


        vector<int> minDice(n * n, 1e9);
        queue<pair<int, int>> q; 
        q.push({0, 0}); 
        minDice[0] = 0;

        while (!q.empty()) {
            auto [pos, rolls] = q.front();
            q.pop();

    
            for (int step = 1; step <= 6; step++) {
                int nextPos = pos + step;
                if (nextPos >= n * n) break;

               
                if (all[nextPos] != -1) {
                    nextPos = all[nextPos] - 1;
                }


                if (minDice[nextPos] > rolls + 1) {
                    minDice[nextPos] = rolls + 1;
                    q.push({nextPos, rolls + 1});
                }
            }
        }


        return minDice[n * n - 1] == 1e9 ? -1 : minDice[n * n - 1];
    }
};
