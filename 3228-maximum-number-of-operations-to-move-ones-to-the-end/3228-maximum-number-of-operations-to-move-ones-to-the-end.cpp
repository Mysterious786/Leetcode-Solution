class Solution {
public:
    int maxOperations(string s) {
        int n = size(s);
        int count = 0;
        int ans = 0;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch == '1' and flag) count++;
            if(ch == '0' and flag) flag = 0;
            if(ch == '1' and flag == 0)
            {
                ans+=count;
                count++;
                flag=!flag;
            }
        }
        if(!flag) ans+=count;
        return ans;
    }
};