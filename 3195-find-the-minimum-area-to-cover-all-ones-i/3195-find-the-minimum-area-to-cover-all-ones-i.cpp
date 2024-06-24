class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int maxi=0,mini=INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> hor,ver;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   hor.push_back(j);
                   ver.push_back(i);
                }
            }
        }
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        return (hor[hor.size()-1]-hor[0]+1)*(ver[ver.size()-1]-ver[0]+1);
    }
};