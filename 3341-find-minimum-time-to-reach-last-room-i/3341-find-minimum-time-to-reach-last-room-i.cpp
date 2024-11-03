#define ll long long
class Solution {
    ll n, m;
    vector<ll> dx = {0, 0, -1, 1}; // movements in x direction
    vector<ll> dy = {1, -1, 0, 0}; // movements in y direction
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();
        
        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> q;
        q.push({0ll, {0, 0}});
        vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MAX));
        dp[0][0] = 0ll;

        while (!q.empty()) {
            auto front = q.top();
            q.pop();
            ll row = front.second.first;
            ll col = front.second.second;
            ll currTime = front.first;

            if (currTime > dp[row][col]) continue; // Skip if we've already found a faster way to this cell

            for (int i = 0; i < 4; i++) {
                ll newRow = row + dx[i];
                ll newCol = col + dy[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    ll nextTime = max(currTime,(ll) moveTime[newRow][newCol]) + 1;
                    
                    // Update if we found a faster way to reach (newRow, newCol)
                    if (dp[newRow][newCol] > nextTime) {
                        dp[newRow][newCol] = nextTime;
                        q.push({nextTime, {newRow, newCol}});
                    }
                }
            }
        }
        return dp[n - 1][m - 1] == LLONG_MAX ? -1 : dp[n - 1][m - 1];
    }
};
