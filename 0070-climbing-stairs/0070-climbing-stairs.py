class Solution:
    def tot_ways_to_climb(self, n:int, dp: List[int]) -> int:
        if n == 0:
            return 1
        if n < 0:
            return 0
        if dp[n] != -1:
            return dp[n]
        take_one_step = self.tot_ways_to_climb(n-1, dp)
        take_two_steps = self.tot_ways_to_climb(n-2, dp)
        ans =  take_one_step + take_two_steps
        dp[n] = ans
        return ans
    def climbStairs(self, n: int) -> int:
        dp = [-1]*(n+1)
        return self.tot_ways_to_climb(n, dp)
        
        
        