class Solution:
    def rob_the_money(self, ind: int, nums: List[int],dp: List[int]):
        if ind == len(nums)-1:
            return nums[ind]
        if ind >= len(nums):
            return 0
        if dp[ind] != -1:
            return dp[ind]
        not_take = self.rob_the_money(ind+1,nums,dp)
        take = nums[ind] + self.rob_the_money(ind+2,nums,dp)
        dp[ind] = max(take,not_take)
        return dp[ind]
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        dp = [-1]*n
        return self.rob_the_money(0,nums,dp)
        