class Solution {
   int dx[4] = {-1, 1, 0, 0}; 
   int dy[4] = {0, 0, 1, -1};
private:
    void dfs(int row,int col,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis,int n,int m,bool& yes){
        if(row<0 or row>=n or col>=m or col<0 or vis[row][col]==1 or grid2[row][col]==0) return;
        if(grid1[row][col] == 0 and grid2[row][col]==1) yes = false;
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int newRow = dx[i] + row;
            int newCol = dy[i] + col;
            dfs(newRow,newCol,grid1,grid2,vis,n,m,yes);
        }

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid1[row][col]==1 and grid2[row][col]==1 and !vis[row][col]){
                    bool yes = true;
                    dfs(row,col,grid1,grid2,vis,n,m,yes);
                    if(yes) ans++;
                }
            }
        }
        return ans;
    }
};