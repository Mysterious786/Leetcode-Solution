int dp[101][1234];
class Solution {
private:
	int f(int num,int mask,vector<vector<int>>& grid)
	{
		if(num > 100) return 0;
		if(dp[num][mask]!=-1) return dp[num][mask];
		int ans = 0;
		ans = f(num+1,mask,grid);
		for(int i=0;i<grid.size();i++)
		{
			if(mask&(1<<i)) continue;
			for(int j=0;j<grid[0].size();j++)
			{
				if(grid[i][j]!=num) continue;
				ans = max(ans,num+f(num+1,mask|(1<<i),grid));

			}
		}
		return dp[num][mask] = ans;
	}
public:
    int maxScore(vector<vector<int>>& grid) {
    	memset(dp,-1,sizeof(dp));
        return f(1,0,grid);
    }
};