class Solution {

static constexpr int MOD = 1000000007;


public:
    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        

    for(long long absent = 0;absent<=1;absent++){
        for(long long late = 0;late<3;late++){
            dp[0][absent][late] = 1;
        }
    }
    for(long long left = 1;left<=n;left++){
        for(long long absent =0;absent<=1;absent++){
            for(long long late =0;late<3;late++){
                 long long take = 0;
        take += dp[left-1][absent][0];
        if (absent > 0) {
            take += dp[left-1][absent-1][0];
        }
        if (late + 1 < 3) {
            take += dp[left-1][absent][late+1];
        }
         dp[left][absent][late] = take%MOD;
            }
        }
    }
   return  static_cast<int>(dp[n][1][0]);

    }
};