class Solution {
    int dp[105][105];
private:
    int getUniquePaths(int row, int col, int m, int n)
    {

        if(row == m-1 and col == n-1) return 1;
        if(row<0 or row>=m or col<0 or col>=n ) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int right = getUniquePaths(row,col+1,m,n);
        int bottom = getUniquePaths(row+1,col,m,n);
        return dp[row][col] = bottom+right;

    }
public:
    int uniquePaths(int m, int n) {
        // dp[row][col]
        memset(dp,-1,sizeof(dp));
        return getUniquePaths(0,0,m,n);
    }
};