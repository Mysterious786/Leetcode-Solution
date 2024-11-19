// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j





class Solution {
public:
    int minJumps(vector<int>& arr) {
        // lets store every value first of all

        map<int,vector<int>> mp;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            int num = arr[i];
            mp[num].push_back(i);
        }
    vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0] = 1;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.second;
            int ind = it.first;
            if(ind == n-1)
            {
                return steps;
            }
            if(ind-1>=0 and !vis[ind-1])
            {
                vis[ind-1] = 1;
                q.push({ind-1,steps+1});
            }
            if(ind+1 < n and !vis[ind+1])
            {
                q.push({ind+1,steps+1});
                vis[ind+1] = 1;
            }
            int num = arr[ind];
            for(auto it : mp[num])
            {
                if(!vis[it])
                {
                    q.push({it,steps+1});
                    vis[it] = 1;
                }
            }
            mp[num].clear();

        }
        return -1;

    }
};