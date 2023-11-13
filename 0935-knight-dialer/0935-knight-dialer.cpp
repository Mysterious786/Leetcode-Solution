#define ll long long

class Solution {
private:
    const static long long MOD = 1e9 + 7;
    vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    ll helper(int row, int col, int currentLimit, vector<vector<vector<ll>>>& dp) {
        if (row < 0 || col < 0 || row >= 4 || col >= 3 || (row == 3 && (col == 0 || col == 2))) return 0;
        if (currentLimit == 1) return 1;
        if (dp[currentLimit][row][col] != -1) return dp[currentLimit][row][col];
        ll ans = 0;
        for (int i = 0; i < dx.size(); i++) {
            ans += helper(row + dx[i], col + dy[i], currentLimit - 1, dp) % MOD;
        }
        return dp[currentLimit][row][col] = ans % MOD;
    }

public:
    int knightDialer(int n) {
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(4, vector<ll>(3, -1)));
        ll ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                ans += helper(i, j, n, dp) % MOD;
            }
        }

        return static_cast<int>(ans % MOD);
    }
};
