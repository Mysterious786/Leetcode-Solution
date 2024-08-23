class Solution {
    long long dp[10][2][2];
public:
    long long f(int ind,int tight,bool validNum,string& s,vector<string>& digits){
        if(s.size()==ind){
           if(validNum) return 1;
            return 0;
        }
        if(dp[ind][tight][validNum]!=-1) return dp[ind][tight][validNum];

        long long ans = 0;
        // leading zeros
         int limit = tight ? s[ind]-'0':9;
        if(validNum==false) ans+=f(ind+1,false,false,s,digits);
       
        for(auto it : digits){
            int digit = stoi(it);
            int newTight = tight&(digit==limit);
            if(digit > limit) break;
            ans+=f(ind+1,newTight,true,s,digits);
        }
        return dp[ind][tight][validNum] = ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // what I need (ind,tight,validNum,str);
        // upperbound = n;
        string upperBound = to_string(n);
        memset(dp,-1,sizeof(dp));
        long long ans = f(0,true,false,upperBound,digits);
        return static_cast<int>(ans);
    }
};