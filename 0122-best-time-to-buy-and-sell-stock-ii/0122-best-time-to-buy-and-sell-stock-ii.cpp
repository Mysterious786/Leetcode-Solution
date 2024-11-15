class Solution {
    int dp[30005][2];
private:
    int totalMaxProfit(int ind, int byOrSell,vector<int>& prices, int n)
    {
        // base case
        if(ind == n)
        {
            return 0;
        }
        if(dp[ind][byOrSell]!=-1) return dp[ind][byOrSell];
        int buy = 0,sell = 0;

        if(!byOrSell) // no stock currently
        {
            buy = max(totalMaxProfit(ind+1,byOrSell,prices,n),-prices[ind] + totalMaxProfit(ind+1,!byOrSell,prices,n));
        }
        else
        {
            sell = max(totalMaxProfit(ind+1,byOrSell,prices,n),prices[ind] + totalMaxProfit(ind+1,!byOrSell,prices,n));
        }
        return dp[ind][byOrSell] = max(buy,sell);
    }
public:
    int maxProfit(vector<int>& prices) {
     int n = prices.size();
     memset(dp,-1,sizeof(dp));
     // dp[ind][buy/sell].... buy == false sale = false
     return totalMaxProfit(0,0,prices,n);   
    }
};