class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count_zero = 0
        start = 0
        end = 0
        ans = 0
        while end < n:
            if nums[end] == 0 and count_zero <= k:
                count_zero+=1
            while count_zero>k:
                if nums[start]==0:
                    count_zero-=1;
                start+=1
            ans = max(ans,end-start+1)
            end+=1
        return ans
        