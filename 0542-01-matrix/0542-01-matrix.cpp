class Solution {
     int dx[4] = {0, 0, 1, -1};
     int dy[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int steps = it.second;
            dis[row][col] = steps;
            for(int i=0;i<4;i++){
                int newRow = row+dx[i];
                int newCol = col+dy[i];
                if(newRow<0 or newRow>=n or newCol<0 or newCol>=m or vis[newRow][newCol]!=0) continue;
                else{
                    q.push({{newRow,newCol},steps+1});
                    vis[newRow][newCol]=1;
                }
            }
            
        }
        return dis;
        
    }
};