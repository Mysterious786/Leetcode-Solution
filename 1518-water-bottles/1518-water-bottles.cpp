class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int remain = numBottles;
        int filled = 0;
        while(remain >= numExchange){
            int current = remain/numExchange;
            ans+=current;
            remain = remain%numExchange;
            remain+=current;
        }
        return ans;
        
        
    }
};