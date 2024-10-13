#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = size(nums);
        vector<int> ans;
        for(int i=0;i+k<=n;i++)
        {
            map<int,int> mp;
            vector<pair<int,int>> v;
            int start = i;
            int window = k;
            int need = x;
            int sum = 0;
            while(start < n and window--)
            {
                mp[nums[start]]++;
                start++;
                
            }
            for(auto it : mp) v.push_back({it.second,it.first});
            sort(v.begin(),v.end(),greater<pair<int,int>>());
            int sz;
            if(v.size() >= x) sz = x;
            else sz = v.size();
            for(int j=0;j<sz;j++)
            {
                sum+=(v[j].first*v[j].second);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};