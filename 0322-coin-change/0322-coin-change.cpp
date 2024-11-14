class Solution {
    long long totalCoinChage(int ind, int n, vector<int>& coins, int amount,vector<vector<int>>& dp)
    {
        if(ind == n-1)
        {
            if(amount%coins[ind]==0) return amount/coins[ind];
            return INT_MAX;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        long long notTake = totalCoinChage(ind+1,n,coins,amount,dp);
        long long take = INT_MAX;
        if(amount >= coins[ind])
        {
            take = 1 + totalCoinChage(ind,n,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = static_cast<int>(totalCoinChage(0,n,coins,amount,dp));
        if(ans >= INT_MAX) return -1;
        return ans;
    }
};