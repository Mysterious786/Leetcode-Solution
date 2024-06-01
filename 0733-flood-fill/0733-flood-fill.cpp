class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     queue<pair<int,int>> q;
        
        q.push({sr,sc});
        int val = image[sr][sc];
        image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto ele = q.front();
                int row = ele.first;
                int col = ele.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newRow = row+dx[i];
                    int newCol = col+dy[i];
                    if(newRow<0 or newRow>=n or newCol<0 or newCol>=m or image[newRow][newCol]!=val or image[newRow][newCol]==color){
                        continue;
                    }
                    else{
                        q.push({newRow,newCol});
                        image[newRow][newCol] = color;
                    }
                }
                
            }
            
        }
        return image;
    }
};