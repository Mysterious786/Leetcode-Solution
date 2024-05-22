class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int ans =0;
        for(int i=0;i<n;i++){
            mini = min(prices[i],mini);
            ans = max(ans,prices[i]-mini);
            
        }
        return ans;
        
    }
};