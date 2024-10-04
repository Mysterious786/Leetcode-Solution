class Solution:
    def total_unique_path(self, row: int, col: int, n: int, m: int, dp: List[List[int]]):
        if row >= n or col >= m:
            return 0
        if row == n-1 and col == m-1:
            return 1
        if dp[row][col] != -1:
            return dp[row][col]
        right = self.total_unique_path(row, col+1, n, m, dp)
        down = self.total_unique_path(row+1, col, n, m, dp)
        dp[row][col] = right + down
        return dp[row][col]

    def uniquePaths(self, m: int, n: int) -> int:
        #dp = [[-1]*m for _ in range(n)]  # Correct deep copy for the dp matrix
        dp = [[-1]*m for _ in range(n)]
        return self.total_unique_path(0, 0, n, m, dp)
