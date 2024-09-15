class Solution {
public:
    int findTheLongestSubstring(string words) {


        int count = 0;
        map<int,int> mp;
        mp[0] = -1;
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            char ch = words[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            {
                count = count ^ (1<<(ch-'a'));
            }
            if(mp.find(count)!=mp.end())
            {
                ans = max(ans,i-mp[count]);
            }
            else
            {
                mp[count] = i;
            }
        }
        return ans;
    }
};
