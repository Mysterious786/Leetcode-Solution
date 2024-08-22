class Solution {
    int dp[25][10][500];
    const static long long MOD = 1e9+7;
private:
    long long f(int ind, bool tight, int sum, int minSum, int maxSum, string& s) {
        if (sum > maxSum) return 0;
        if (ind == s.size()) {
            return (minSum <= sum && sum <= maxSum);
        }
        if (dp[ind][tight][sum] != -1) {
            return dp[ind][tight][sum];
        }
        long long count = 0;
        int limit = tight ? s[ind] - '0' : 9;
        for (int digit = 0; digit <= limit; digit++) {
            int newTight = tight && (digit == limit);
            count = (count + f(ind + 1, newTight, sum + digit, minSum, maxSum, s)) % MOD;
        }
        return dp[ind][tight][sum] = count % MOD;
    }
public:
    int count(string num1, string num2, int minSum, int maxSum) {
        auto reduceByOne = [](string& num) {
            int n = num.size();
            for (int i = n - 1; i >= 0; --i) {
                if (num[i] > '0') {
                    num[i]--;
                    break;
                } else {
                    num[i] = '9';
                }
            }
            if (num[0] == '0') {
                num.erase(num.begin());
            }
        };
        
        memset(dp, -1, sizeof(dp));
        reduceByOne(num1);
        long long first = f(0, true, 0, minSum, maxSum, num1);
        
        memset(dp, -1, sizeof(dp));
        long long second = f(0, true, 0, minSum, maxSum, num2);
        
        return static_cast<int>((second - first + MOD) % MOD);
    }
};
