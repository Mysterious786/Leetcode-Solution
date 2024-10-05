class Solution:
    def find_min_sum(self,row: int, col: int, n: int, m: int, grid: List[List[int]], dp: List[List[int]]):
        if row >= n or col >= m:
            return float('inf')
        if row == n-1 and col == m-1:
            return grid[row][col]
        if dp[row][col] != -1:
            return dp[row][col]
        right = grid[row][col] + self.find_min_sum(row,col+1,n,m,grid,dp)
        down = grid[row][col] + self.find_min_sum(row+1,col,n,m,grid,dp)
        dp[row][col] = min(right,down)
        return dp[row][col]
        
        
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[-1]*m for _ in range(n)]
        return self.find_min_sum(0,0,n,m,grid,dp)
        