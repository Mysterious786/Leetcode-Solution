from sortedcontainers import SortedList

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        sorted_list = SortedList([])
        res = []
        for i in range(len(nums)-1,-1,-1):
            num = nums[i]
            pos = sorted_list.bisect_left(num)
            res.append(pos)
            sorted_list.add(num)
        res.reverse()
        return res