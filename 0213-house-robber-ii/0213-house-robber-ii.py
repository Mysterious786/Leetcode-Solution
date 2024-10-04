from typing import List

class Solution:
    def f(self, ind: int, num: List[int], dp: List[int]) -> int:
        if ind < 0:
            return 0
        if ind == 0:
            return num[0]
        if dp[ind] != -1:
            return dp[ind]
        
        # Two choices: don't take the current house, or take it and skip the previous one
        not_take = self.f(ind - 1, num, dp)
        take = num[ind] + self.f(ind - 2, num, dp)
        dp[ind] = max(take, not_take)
        return dp[ind]

    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        
        # Case 1: Rob houses from 0 to n-2 (skip the last house)
        temp1 = nums[:-1]
        dp1 = [-1] * len(temp1)
        first = self.f(len(temp1) - 1, temp1, dp1)
        
        # Case 2: Rob houses from 1 to n-1 (skip the first house)
        temp2 = nums[1:]
        dp2 = [-1] * len(temp2)
        second = self.f(len(temp2) - 1, temp2, dp2)
        
        # The maximum of both cases gives the result
        return max(first, second)

        

        