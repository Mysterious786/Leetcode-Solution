class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start == goal) return 0;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int startBit = start&(1<<i);
            int goalBit = goal&(1<<i);
            if(!startBit and goalBit) ans++;
            if(startBit and !goalBit) ans++;
        }
        return ans;
        
    }
};