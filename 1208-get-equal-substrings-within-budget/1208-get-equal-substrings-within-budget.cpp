class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int sum =0;
        int start=0,end=0;
        int n = s.size();
        while(end<n){
           maxCost-=abs((s[end]-'0')-(t[end]-'0'));
            if(maxCost<0){
                maxCost+=abs((s[start]-'0')-(t[start++]-'0'));
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
        
        
    }
};