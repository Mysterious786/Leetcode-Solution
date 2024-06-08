class Solution {
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Edge case
        if(grid[0][0]==1) return -1;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dis[0][0] = 1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto q = pq.top();
            pq.pop();
            int dist = q.first;
            int row = q.second.first;
            int col = q.second.second;
            for(int i=0;i<8;i++){
                int newRow = row+dx[i];
                int newCol = col+dy[i];
                int newDist = dist + 1;
                // check condition
                if(newRow<0 or newCol<0 or newCol>=m or newRow>=n or grid[newRow][newCol]==1) continue;
                if(dis[newRow][newCol] > newDist) {
                    dis[newRow][newCol] = newDist;
                    pq.push({newDist,{newRow,newCol}});
                }
            }
        }
        if(dis[n-1][m-1]==1e9) return -1;
        return dis[n-1][m-1];
         
    }
};