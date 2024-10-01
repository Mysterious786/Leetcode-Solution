class Solution {
public:
    long long maximumTotalSum(vector<int>& m) {
        long long totSum = 0;
        int n = m.size();
        sort(m.begin(),m.end());
        totSum+=m[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(m[i] >= m[i+1])
            {
                m[i] = m[i+1]-1;
            }
            if(m[i]<=0) return -1;
            totSum+=m[i];
        }
        return totSum;
    }
};