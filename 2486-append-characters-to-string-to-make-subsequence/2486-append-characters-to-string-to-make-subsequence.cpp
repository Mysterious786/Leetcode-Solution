class Solution {
public:
    int appendCharacters(string s, string t) {
                int sz = s.size();
        int ts = t.size();
        int i=0,j=0;
        while(i<sz and j<ts){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return ts-j;
    }
};