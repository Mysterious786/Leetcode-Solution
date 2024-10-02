class Solution {
public:
    int minChanges(int n, int k) {
        if(n==k) return 0;
        
        int count = 0;
        
        for(int i=0;i<31;i++)
        {
            int bitmask = (1<<i);
            int bitN = n&bitmask;
            int bitK = k&bitmask;
            
            if(bitN!=0 and bitK == 0)
            {
                n^=bitmask;
                count++;
            }
        }
        return (n==k)?count:-1;
    }
};