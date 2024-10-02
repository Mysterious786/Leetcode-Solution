class Solution {
public:
    int maxOperations(string s) {
        int n = size(s);
        int count  = 0;
        int ans = 0;
        bool flag = 1;
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if(c=='1' and flag == 1) count++;
            if(c=='0' and flag == 1) flag = 0;
            if(c=='1' and flag==0)
            {
                ans+=count;
                count++;
                flag=!flag;
            }
            
        }
        if(flag==0) ans+=count;
        return ans;
    }
};