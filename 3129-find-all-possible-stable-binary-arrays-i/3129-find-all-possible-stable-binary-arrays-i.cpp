class Solution {
    static const int mod = 1e9+7;
    int dp[201][201][2][201];

private:
    int f(int zero, int one, int limit, int flag, int count) {
        if (zero == 0 && one == 0) return 1;
        if(count>limit) return 0;
        if (flag != -1 && dp[zero][one][flag][count] != -1) return dp[zero][one][flag][count];

        int ptZ = 0, ptO = 0;
        if (zero >= 1 && (flag != 0 || count < limit)) {
            ptZ = f(zero - 1, one, limit, 0, flag == 0 ? count + 1 : 1);
        }
        if (one >= 1 && (flag != 1 || count < limit)) {
            ptO = f(zero, one - 1, limit, 1, flag == 1 ? count + 1 : 1);
        }

        if (flag == -1) return (ptZ + ptO) % mod;
        return dp[zero][one][flag][count] = (ptZ + ptO) % mod;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        return f(zero, one, limit, -1, 0);
    }
};

