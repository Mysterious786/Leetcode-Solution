class Solution {
public:
    int arrangeCoins(int n) {
        int count =0;
        int start = 1;
        long long sum =0;
        while(sum<=n){
            count++;
            sum+=start;
            start++;
            
        }
        return count-1;
        
    }
};