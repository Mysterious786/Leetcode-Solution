#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[10][2][10];
private:
    long long f(int ind,int tight,string& s,int ret){
        if(ind==s.size()) return ret;
        if(dp[ind][tight][ret]!=-1) return dp[ind][tight][ret];

        long long ans = 0;
        int limit = tight ? s[ind] - '0' : 9;
        for(int digit = 0;digit<=limit;digit++){
            int newTight = tight&(digit==limit);
            
          
            ans+=f(ind+1,newTight,s,ret+(digit==1));


        }
        return dp[ind][tight][ret] = ans;
    }
public:
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string upperBound = to_string(n);
        // ind,tight,leadingZero
        long long ans = f(0,true,upperBound,0);
        return static_cast<int>(ans);

    }
};

