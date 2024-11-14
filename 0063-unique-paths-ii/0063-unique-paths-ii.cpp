class Solution {
    int dp[105][105];
private:
    int getUniquePathWithObstacles(int row, int col, int n, int m, vector<vector<int>>& obstacleGrid)
    {
       
        if(row>=n or row<0 or col>=m or col<0 or obstacleGrid[row][col] == 1) return 0;
         if(row==n-1 and col == m-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int right = getUniquePathWithObstacles(row,col+1,n,m,obstacleGrid);
        int down = getUniquePathWithObstacles(row+1,col,n,m,obstacleGrid);
        return dp[row][col] = right+down;

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //edge case
       // if()
        memset(dp,-1,sizeof(dp));
        return getUniquePathWithObstacles(0,0,n,m,obstacleGrid);
    }
};