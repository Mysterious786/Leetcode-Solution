class Solution {
    int dp[30005][2][105];
private:
    int totalMaxProfit(int ind, int byOrSell,vector<int>& prices, int n,int transactions)
    {
        // base case
        if(ind == n)
        {
            return 0;
        }
        if(transactions == 0) return 0;
        if(dp[ind][byOrSell][transactions]!=-1) return dp[ind][byOrSell][transactions];
        int buy = 0,sell = 0;

        if(!byOrSell) // no stock currently
        {
            buy = max(totalMaxProfit(ind+1,byOrSell,prices,n,transactions),-prices[ind] + totalMaxProfit(ind+1,!byOrSell,prices,n,transactions));
        }
        else
        {
            sell = max(totalMaxProfit(ind+1,byOrSell,prices,n,transactions),prices[ind] + totalMaxProfit(ind+1,!byOrSell,prices,n,transactions-1));
        }
        return dp[ind][byOrSell][transactions] = max(buy,sell);
    }
public:
    int maxProfit(int k,vector<int>& prices) {
     int n = prices.size();
     // atmost2 transaction
     memset(dp,-1,sizeof(dp));
     // dp[ind][buy/sell].... buy == false sale = false
     // when a buy + sell occur then its a transactions OOOOK..

     return totalMaxProfit(0,0,prices,n,k);   
    }
};