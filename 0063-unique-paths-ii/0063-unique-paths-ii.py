class Solution:
    def unique_path(self, row: int, col: int, n: int, m: int, obs: List[List[int]], dp: List[List[int]])-> int:
        if row >= n or col >= m or obs[row][col] == 1:
            return 0;
        if row == n-1 and col == m-1:
            return 1
        if dp[row][col] != -1:
            return dp[row][col]
        right = self.unique_path(row,col+1,n,m,obs,dp)
        down = self.unique_path(row+1,col,n,m,obs,dp)
        dp[row][col] = right + down
        return dp[row][col]
    def uniquePathsWithObstacles(self, obs: List[List[int]]) -> int:
        n = len(obs)
        m = len(obs[0])
        dp = [[-1]*m for _ in range(n)]
        
        return self.unique_path(0,0,n,m,obs,dp)