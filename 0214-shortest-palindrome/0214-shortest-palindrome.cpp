class Solution {
    private:
    int LPS(string& st){
        int  n = st.size();
        vector<int> lps(n);
        for(int i=1;i<n;i++){
            int len = lps[i-1];
            if(st[i] == st[len]){
                lps[i] = len+1;
            }
            else{
                while(st[i]!=st[len]){
                    if(len == 0){
                        len = -1;
                        break;
                    }
                    len = lps[len-1];
                }
                lps[i]= len +1;
            }
        }
        return lps[n-1];
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string newSt = s+"#"+rev;
        int lps = LPS(newSt);
        string st = s.substr(lps);
        reverse(st.begin(),st.end());
        return st+s; 
        
        
    }
};