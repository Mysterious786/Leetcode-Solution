class Solution:
    def singleNumber(self, nums):
        xori = 0
        a = 0
        b = 0
        for num in nums:
            xori ^= num
        val = xori & -xori  # Isolate the rightmost set bit
        for num in nums:
            if val & num:
                a ^= num
            else:
                b ^= num
        return [a, b]