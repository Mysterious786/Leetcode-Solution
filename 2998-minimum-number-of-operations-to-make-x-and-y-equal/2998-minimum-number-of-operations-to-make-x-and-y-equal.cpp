class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>> q;
        map<int,int> mp;
        q.push({x,0});
        while(!q.empty()){
            auto num = q.front();
            q.pop();
            int op=num.second;
            int n = num.first;
            if(n==y) return op;
            else{
                if(mp.find(n+1) == mp.end()){
                    q.push({n+1,op+1});
                    mp[n+1]++;
                }
                if(mp.find(n-1) == mp.end()){
                    q.push({n-1,op+1});
                    mp[n-1]++;
                }
                if(n%5==0 && mp.find(n/5) ==mp.end()){
                    q.push({n/5,op+1});
                    mp[n/5]++;
                }
                if(n%11==0 && mp.find(n/11) == mp.end()){
                    q.push({n/11,op+1});
                    mp[n/11]++;
                }
            }
        }
        return -1;
        
    }
};