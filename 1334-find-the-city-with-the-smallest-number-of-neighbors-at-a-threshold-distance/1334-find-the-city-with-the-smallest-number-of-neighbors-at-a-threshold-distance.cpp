class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
       for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        dist[u][v] = w;
        dist[v][u] = w;
       }
       for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
       }
       int res = -1;
       int mini = INT_MAX;
       for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(i!=j and dist[i][j]<=distanceThreshold) count++;
        }
        if(mini == count){
            res = i;

        }
           else if(mini > count){
               mini = count;
               res = i;
           }
       }
       return res;
    }
};
