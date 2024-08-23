#include <bits/stdc++.h>
using namespace std;

class Solution {
    const static long long MOD = 1e9+7;
    long long dp[101][2][10][2];   // ind, tight, prev, validNum
private:
    long long f(int index, bool tight, int prev, bool validNum, string& s) {
        if (index == s.size()) {
            return validNum ? 1 : 0;
        }
        if (dp[index][tight][prev][validNum] != -1) return dp[index][tight][prev][validNum];
        
        long long ans = 0;
        int limit = tight ? s[index] - '0' : 9;
        for (int digit = 0; digit <= limit; digit++) {
            bool newTight = tight && (digit == limit);
            if (validNum == false && digit == 0) {  // Leading zeros case
                ans = (ans + f(index + 1, newTight, prev, false, s)) % MOD;
            } else if (validNum == false && digit > 0) {  // First non-zero digit
                ans = (ans + f(index + 1, newTight, digit, true, s)) % MOD;
            } else if (abs(digit - prev) == 1) {  // Valid stepping number continuation
                ans = (ans + f(index + 1, newTight, digit, true, s)) % MOD;
            }
        }
        return dp[index][tight][prev][validNum] = ans;
    }

public:
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        long long countLow = f(0, true, 0, false, low);  // Count of numbers < low
        memset(dp, -1, sizeof(dp));
        long long countHigh = f(0, true, 0, false, high);  // Count of numbers <= high
        
        // Check if "low" itself is a stepping number
        bool isLowStepping = true;
        for (int i = 0; i < low.size() - 1; i++) {
            if (abs((low[i] - '0') - (low[i + 1] - '0')) != 1) {
                isLowStepping = false;
                break;
            }
        }
        
        if (isLowStepping) countLow--;  // Subtract if low is a stepping number
        
        return ((countHigh - countLow) % MOD + MOD) % MOD;
    }
};
