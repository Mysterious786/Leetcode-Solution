class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        start = 0
        end = 0
        maxi = 0
        ans = 0
        mp = {}
        while end < n:
            if s[end] in mp:
                mp[s[end]]+=1
            else:
                mp[s[end]] = 1
            maxi = max(maxi,mp[s[end]])
            while (end-start+1) - maxi > k:
                mp[s[start]] -= 1
                start+=1
            ans = max(ans,end-start+1)
            end+=1
        return ans