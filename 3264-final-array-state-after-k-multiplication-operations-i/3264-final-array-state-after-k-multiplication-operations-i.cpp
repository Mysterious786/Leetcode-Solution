class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto front = pq.top();
            int nums = front.first;
            pq.pop();
            pq.push({nums*multiplier,front.second});
        }
        int n = size(nums);
        vector<int> ans(n,0);
    while(!pq.empty()){
        auto top = pq.top();
        int ele = top.first;
        int ind = top.second;
        ans[ind] = ele;
        pq.pop();
    }
        return ans;
        
    }
};