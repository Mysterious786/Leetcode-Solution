#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int f(int i,int preMod, int& halfn,int& n,int& k,vector<int>& powers,vector<int>& res,vector<vector<int>>& dp){
        if(i==halfn) return preMod == 0;
        if(dp[i][preMod]!=-1) return dp[i][preMod];

        for(int digit = 9;digit>=0; digit--){
            int newMod = preMod;
            // case for odd nd at mid pos
            if((n&1) and (i==halfn-1)){
                // I will count the contribution once
                newMod+=(digit*powers[i])%k;
            }
            else{
                newMod+=(digit*powers[i])%k;
                newMod+=(digit*powers[n-i-1])%k;
            }
            newMod%=k;
            int flag = f(i+1,newMod,halfn,n,k,powers,res,dp);
            if(flag){
                res[i] = digit;
                break;
            }
        }
        if(res[i]==-1) return dp[i][preMod] = 0;
        return dp[i][preMod] = 1;
    }
public:
    string largestPalindrome(int n, int k) {
        int half = (n+1)/2;
        vector<int> res(n,-1);
        vector<vector<int>> dp(half,vector<int>(10,-1));
        vector<int> powers(n,0);
        int prevMod = 0;
        powers[0] = 1%k;
        for(int i=1;i<n;i++){
            powers[i] = (powers[i-1]*10)%k;
        }
        f(0,prevMod,half,n,k,powers,res,dp);
    
    string ans(n, '0');
        for(int i = 0; i < half; i++){
            ans[i] = '0' + res[i];
            ans[n-i-1] = ans[i];
        }
       return ans;
}
};
