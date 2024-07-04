class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        int start = 0, end = 0, ans = 0;
        map<char, int> mp;
        
        while (end < n) {
            mp[s[end]]++;  
            
          
            while (mp[s[end]] > 1) {
                mp[s[start]]--;
                if (mp[s[start]] == 0) {
                    mp.erase(s[start]);
                }
                start++;
            }
            
            ans = max(ans, end - start + 1);
            end++;
        }
        
        return ans;
    }
};
