class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        n = len(s)
        if n == 0:
            return 0
        start=0
        end = 0
        ans = 0
        while end < n:
            if s[end] in mp:
                mp[s[end]] = mp[s[end]] + 1;
            else :
                mp[s[end]] = 1
            while mp[s[end]]>1:
                mp[s[start]]-=1;
                if mp[s[start]] == 0:
                    del mp[s[start]]
                
                start+=1
            
            ans = max(ans,end-start+1)
            end+=1
        return ans
            