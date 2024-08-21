#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        int n = size(s);
        for(int i=0;i<n;i++){
            int countZ(0),countO(0);
            for(int j=i;j<n;j++){
                if(s[j]=='0') countZ++;
                else countO++;
                if(countZ<=k || countO<=k) ans++;
            }
        }
        return ans;
    }
};

// int main(){
//     string st;
//     cin>>st;
//     int k = 1;
//     cin>>k;
//     Solution sol;
//     cout<<sol.countKConstraintSubstrings(st,k)<<endl;
//     return 0;
// }
