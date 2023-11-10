#define ll long long 
class Solution {
    static const ll M = 1e9+7;
    private:
    ll helper(ll ind,ll n,string& s,vector<ll>& dp){
        if(ind == n) return 1;
        if(ind > n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        ll total = 0;
        if(s[ind] == '*')
        
        {
            
            total+=9*helper(ind+1,n,s,dp);
            total%=M;
           if(ind+1<n){
              if(s[ind+1] == '*') total+=15*helper(ind+2,n,s,dp);
               else if(s[ind+1] <= '6' ) total+=2*helper(ind+2,n,s,dp);
               else total+=helper(ind+2,n,s,dp);
               
               
           }
            
            
            
            
            
        }
        
        
        
        else{
            if(s[ind]!='0')
            total+=helper(ind+1,n,s,dp);
            
            if(s[ind] == '1' && ind+1 < n){
                if(s[ind+1] == '*') total+=9*helper(ind+2,n,s,dp);
                else total+=helper(ind+2,n,s,dp);
            }
            
             if(s[ind] == '2' && ind+1 < n){
                if(s[ind+1] == '*') total+=6*helper(ind+2,n,s,dp);
                else if(s[ind+1] <='6') total+=helper(ind+2,n,s,dp);
            }
            
        }
        return dp[ind] = total%M;
        
        
    }
    
public:
    int numDecodings(string s) {
        ll n = s.size();
        vector<ll> dp(n+1,-1);
        return static_cast<int>(helper(0,n,s,dp));
        
        
    }
};