class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int> mp;
        int odd =0;
        for(auto it : s){
            mp[it]++;
            if(mp[it]%2) odd++;
            else odd--;
        }
        if(odd>1)  return s.length()-odd+1;
        return s.length();
        
    }
};