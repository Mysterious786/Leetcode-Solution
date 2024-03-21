class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        //if(n < k) return s;
        if(n <= k){
            reverse(s.begin(),s.end());
            return s;
        }
        int start =0;
        while(n-start >= k){
            reverse(s.begin()+start,s.begin()+start+k);
            start+=2*k;
        }
        reverse(s.begin()+start,s.end());
        return s;
    }
};