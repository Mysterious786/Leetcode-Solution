class Solution {
private:
    int increasingPathCalculation(int row,int col,vector<vector<int>>& matrix,int n,int m,int dx[],int dy[],vector<vector<int>>& dp){
        if(row>=n || row<0 || col>=m || col<0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int take = 0;
        for(int i=0;i<4;i++){
            int newRow = row+dx[i];
            int newCol = col+dy[i];
            if(newRow>=n || newRow<0 || newCol>=m || newCol<0||matrix[newRow][newCol] <= matrix[row][col]) continue;
            take = max(take,1+increasingPathCalculation(newRow,newCol,matrix,n,m,dx,dy,dp));
        }
        return dp[row][col] =  take;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        // dp(i)(j) => total increasing path that start from i,j
        vector<vector<int>> dp(rowSize+1,vector<int>(colSize+1,-1));
        int ans = 1;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                ans = max(ans,1+increasingPathCalculation(i,j,matrix,rowSize,colSize,dx,dy,dp));
            }
        }
        return ans; 
        
    }
};