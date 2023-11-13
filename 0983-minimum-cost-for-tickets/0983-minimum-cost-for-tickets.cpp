class Solution {
private:
    int helper(int day, map<int, int>& mp, vector<int>& costs,vector<int> &dp) {
        if (day <= 0) return 0;
        if(dp[day]!=-1) return dp[day];
        if (mp.find(day) != mp.end()) {
            int day1 = costs[0] + helper(day - 1, mp, costs,dp);
            int day2 = costs[1] + helper(day - 7, mp, costs,dp);
            int day3 = costs[2] + helper(day - 30, mp, costs,dp);
            return dp[day] = min({day1, day2, day3});
        }

        return dp[day] = helper(day - 1, mp, costs,dp);
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       vector<int> dp(366,-1);
        map<int, int> mp;
        for (auto it : days) mp[it];

        return helper(365, mp, costs,dp);
    }
};
