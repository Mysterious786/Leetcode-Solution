class Solution {
public:
    int hammingDistance(int x, int y) {
        int end = 31;
        int count =0;
        for(int i=0;i<end;i++){
            int first = (1<<i)&x;
            int second = (1<<i)&y;
            if(first!=second) count++;
            
        }
        return count;
        
    }
};