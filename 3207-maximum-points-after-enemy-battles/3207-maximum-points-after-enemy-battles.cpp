
#define inty long long
class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        inty n = e.size();
        inty start =0,end=n-1;
        inty point =0;
        sort(e.begin(),e.end());
        if(c<e[0]) return 0;
        while(start<=end){
            if(c>=e[start]){
                point +=(c/e[start]);
                c=c%e[start];
                
            }
            else if(point){
                c+=e[end];
                end--;
               
            }
           
            
        }
        return point;
        
    }
};