class Solution {
public:
    int minChanges(int n, int k) {
        if(n==k) return 0;
        if(n<k) return -1;
        int count = 0;
        while(n>0 and k>0)
        {
            int rem1 = n%2;
            int rem2 = k%2;
            if(rem1==1 and rem2==0) count++;
            if(rem1 == 0 and rem2 == 1) return -1;
            n/=2;
            k/=2;
        }
        while(n>0)
        {
            count+=(n%2);
            n/=2;
        }
        return count;
    }
};