class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
    	vector<vector<int>> x(n+1,vector<int>(m+1,0));
    	vector<vector<int>> y(n+1,vector<int>(m+1,0));

    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			x[i][j] = x[i-1][j]+x[i][j-1]-x[i-1][j-1]+(grid[i-1][j-1]=='X'?1:0);
    			y[i][j] = y[i-1][j]+y[i][j-1]-y[i-1][j-1]+(grid[i-1][j-1]=='Y'?1:0);
    		}
    	}
    	int ans =0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			int val1 = x[i][j];
    			int val2 = y[i][j];
    			if(val1>0 and val1==val2) ans++;
    		}
    	}
    	return ans;
        
    }
};
