class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[4][1001][2001]; // Adjust dp sizes

    long long solveMem(string &s, int prev, int curr, long long bob) {
        if (curr >= s.size()) {
            return bob > 0 ? 1 : 0; // Valid winning sequence if Bob's score is greater than 0
        }

        if (bob < -1000 || bob > 1000) // Check bounds for bob
            return 0;

        if (dp[prev + 1][curr][bob + 1000] != -1) 
            return dp[prev + 1][curr][bob + 1000];

        long long f = 0, w = 0, e = 0;

        if (s[curr] == 'F') {
            if (prev != 0) 
                f = solveMem(s, 0, curr + 1, bob) % MOD;
            if (prev != 1) 
                w = solveMem(s, 1, curr + 1, bob + 1) % MOD;
            if (prev != 2) 
                e = solveMem(s, 2, curr + 1, bob - 1) % MOD;
        } 
        else if (s[curr] == 'W') {
            if (prev != 0) 
                f = solveMem(s, 0, curr + 1, bob - 1) % MOD;
            if (prev != 1) 
                w = solveMem(s, 1, curr + 1, bob) % MOD;
            if (prev != 2) 
                e = solveMem(s, 2, curr + 1, bob + 1) % MOD;
        } 
        else { 
            if (prev != 0) 
                f = solveMem(s, 0, curr + 1, bob + 1) % MOD;
            if (prev != 1) 
                w = solveMem(s, 1, curr + 1, bob - 1) % MOD;
            if (prev != 2) 
                e = solveMem(s, 2, curr + 1, bob) % MOD;
        }

        // Apply MOD after summation
        return dp[prev + 1][curr][bob + 1000] = (f + w + e) % MOD;
    }

    int countWinningSequences(string s) {
        long long ans = 0;
        memset(dp, -1, sizeof(dp));

        ans = solveMem(s, -1, 0, 0);

        return (ans + MOD) % MOD; // Return positive modulo result
    }
};
