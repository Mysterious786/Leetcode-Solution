class Solution {
    vector<vector<long long>> dp;
private:
    long long totalCoinChange(int ind, int n, vector<int>& coins, int amount,vector<vector<long long>>& dp)
    {
      if(ind == n-1)
      {
        if(amount%coins[ind]==0) return 1;
        return 0;
      }  
      if(amount==0) return 1;
      if(dp[ind][amount]!=-1) return dp[ind][amount];
      long long notTake = 0 + totalCoinChange(ind+1,n,coins,amount,dp);
      long long take = 0;
      if(amount>=coins[ind])
      {
        take = totalCoinChange(ind,n,coins,amount-coins[ind],dp);
      }
      return dp[ind][amount] = take+notTake;
 
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.clear();
        dp.resize(n+1,vector<long long>(amount+1,-1));
        return static_cast<int>(totalCoinChange(0,n,coins,amount,dp));
    }
};