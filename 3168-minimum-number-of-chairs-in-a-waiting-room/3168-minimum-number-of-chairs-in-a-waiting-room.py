class Solution:
    def minimumChairs(self, s: str) -> int:
        enter = 0
        ans = 0
        for x in s:
            if x == 'E':
                enter = enter + 1
            else:
                enter = enter - 1
            ans = max(ans,enter)
        return ans
    