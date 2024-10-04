class Solution:
    
    def stair_case(self, n, dp):
        if n == 0:
            return 1
        if n < 0:
            return 0
        if dp[n]!=-1:
            return dp[n]
        one_step = self.stair_case(n-1, dp)
        two_step = self.stair_case(n-2, dp)
        dp[n] = one_step + two_step
        return dp[n]
        
    def climbStairs(self, n: int) -> int:
        dp = [-1]*(n+1)
        return self.stair_case(n,dp)