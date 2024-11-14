class Solution {
    int dp[205][205];
private:
    long long getMinPathSum(int row, int col, int n, int m,vector<vector<int>>& grid)
    {
        if(row>=n or row<0 or col>=m or col<0) return INT_MAX;
        if(row == n-1 and col == m-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        long long right = grid[row][col] + getMinPathSum(row,col+1,n,m,grid);
        long long down  = grid[row][col] + getMinPathSum(row+1,col,n,m,grid);
        return dp[row][col] = min(right,down);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return static_cast<int>(getMinPathSum(0,0,n,m,grid));
    }
};