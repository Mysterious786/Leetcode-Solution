class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i=0
        j=0
        n = len(g)
        m = len(s)
        ans = 0
        while i<n and j<m:
            if s[j] >= g[i]:
                ans = ans + 1
                j = j+1
                i = i+1
            else:
                j = j + 1
        return ans
        