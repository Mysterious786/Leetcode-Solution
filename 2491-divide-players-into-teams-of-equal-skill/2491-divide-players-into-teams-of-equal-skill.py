class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        left = 0
        n = len(skill)
        right = n-1
        ans = 0
        st =  set()
        while left < right :
            ans = ans  + (skill[left] * skill[right])
            st.add(skill[left] + skill[right])
            left = left + 1
            right = right - 1
        if len(st) > 1:
            return -1
        return ans
            