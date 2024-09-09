class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        stack<int> st;
        int n = nums.size();
        vector<int> next(n, n-1);
        st.push(n-1);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() and nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) next[i] = n-1;
            else next[i] = st.top();
            st.push(i);
        }
        int i = 0;
        while(i < n) {
            int idx = next[i];
            if(idx == i) {
                ans += (n-1-i) *1LL* nums[i];
                break;
            }
            ans += (idx - i) *1LL* nums[i];
            i = idx;
        }
        return ans;
    }
};