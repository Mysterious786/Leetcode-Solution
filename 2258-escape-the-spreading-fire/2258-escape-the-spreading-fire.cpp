class Solution {
    private:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    int check(long long mid,vector<vector<long long>> &time){
        int m = time.size();
        int n = time[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> pq;
        if(time[0][0] < mid){
            return false;
        }
        pq.push({mid,{0,0}});
        while(!pq.empty()){
             long long  wait = pq.top().first;
             int x = pq.top().second.first;
             int y = pq.top().second.second;

             pq.pop();
             if(x==m-1 && y==n-1) return true;
            for(int i=0;i<4;i++)
            {
                int nx=x+dr[i];
                int ny=y+dc[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n && time[nx][ny] != -1)
                {
                    long long firetime = time[nx][ny];
                    if(nx == m-1 && ny == n-1 && wait+1 == firetime) return true;
                    if(wait+1 < firetime && visited[nx][ny] == 0)
                    {
                        visited[nx][ny] = 1;
                        pq.push({wait+1,{nx,ny}});
                    }
                }
            }

        }
        return false;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> fireTimeCell(m,vector<long long>(n,1000000002));
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j] == 1){
                  pq.push({0,{i,j}});
                  fireTimeCell[i][j] = 0;
               }
               if(grid[i][j] == 2){
                fireTimeCell[i][j] = -1;
               }
            }
        }
        while(!pq.empty()){
            long long time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                 int newrow = dr[i]+row;
                 int newcol = dc[i]+col;
                 if(newrow >=0 && newrow < m && newcol >=0 && newcol < n && grid[newrow][newcol] == 0){
                      if(fireTimeCell[newrow][newcol] > time+1){
                         fireTimeCell[newrow][newcol] = time+1;
                         pq.push({time+1,{newrow,newcol}});
                      }
                 }
            }
        }
        long long low=0;
        long long high=n*m+1;
        long long  ans=-1;

        while(low<=high)
        {
            long long  mid=low+(high-low)/2;

            if(check(mid,fireTimeCell)==true)
            {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(ans >= m*n) return 1e9;
        return ans;
    }
};