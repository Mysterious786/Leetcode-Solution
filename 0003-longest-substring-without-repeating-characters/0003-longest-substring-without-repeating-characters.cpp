class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute Force
        
        int n = s.size();
        if(n==0) return 0;
        int ans = 1;
        for(int i=0;i<n;i++){
            map<char,int> mp;
            bool extra = false;
            int j =i;
            for(;j<n;j++){
                if(mp.find(s[j])==mp.end()){
                    mp[s[j]]++;
                    ans = max(ans,j-i+1);
                }
                else{
                    extra = true;
                    break;
                }
                
            }
            
            
        }
        return ans;
        
    }
};