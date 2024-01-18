class Solution {
    private:
    int f(int stair,int n,vector<int>& dp){
        if(stair > n) return 0;
        if(stair == n) return 1;
        if(dp[stair]!=-1) return dp[stair];
        int first = f(stair+1,n,dp);
        int second = f(stair+2,n,dp);
        return dp[stair] = first+second;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(0,n,dp);
        
    }
};