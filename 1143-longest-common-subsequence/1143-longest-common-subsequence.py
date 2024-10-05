class Solution:
    def find_longest(self,i: int,j: int,n: int,m: int,text1: str,text2: str,dp: List[int]):
        if i >= n or j >= m:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        match = 0
        not_match1 = 0
        not_match2 = 0
        if text1[i]!=text2[j]:
            not_match1 = self.find_longest(i+1,j,n,m,text1,text2,dp)
            not_match2 = self.find_longest(i,j+1,n,m,text1,text2,dp)
        else:
            match = 1 + self.find_longest(i+1,j+1,n,m,text1,text2,dp)
        dp[i][j] = max(not_match1,not_match2,match)
        return dp[i][j]
            
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        dp = [[-1]*m for _ in range(n)]
        return self.find_longest(0,0,n,m,text1,text2,dp)