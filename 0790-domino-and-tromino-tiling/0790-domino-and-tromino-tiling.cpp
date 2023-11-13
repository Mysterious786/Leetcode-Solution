class Solution {
    private:
    const static long long MOD = 1E9+7;
    int helper(int ind,int n,int noDanger,vector<vector<long long>>& dp){
        if(ind == n && noDanger) return 1;
        
        if(ind >= n) return 0;
        if(dp[ind][noDanger] !=-1) return dp[ind][noDanger];
        long long ans = 0;
        if(noDanger){
            ans+=helper(ind+1,n,1,dp);
            ans+=helper(ind+2,n,1,dp);
            ans+=2*helper(ind+1,n,0,dp);
            
        }
        else{
            ans+=helper(ind+1,n,0,dp);
            ans+=helper(ind+2,n,1,dp);
        }
        return dp[ind][noDanger] = static_cast<int>(ans%MOD);
        
    }
public:
    int numTilings(int n) {
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return helper(0,n,1,dp);
        
    }
};