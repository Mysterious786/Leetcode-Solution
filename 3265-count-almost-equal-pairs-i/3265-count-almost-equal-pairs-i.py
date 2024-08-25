class Solution:
    def countPairs(self, nums: List[int]) -> int:
        freq = Counter()
        for i, x in enumerate(nums): 
            freq[x] += 1
            s = list(str(x).zfill(6))
            for j in range(6):
                for k in range(j+1, 6): 
                    if s[j] != s[k]: 
                        s[j], s[k] = s[k], s[j]
                        cand = int("".join(s))
                        freq[cand] += 1
                        s[j], s[k] = s[k], s[j]
        return sum(freq[x]-1 for x in nums)//2