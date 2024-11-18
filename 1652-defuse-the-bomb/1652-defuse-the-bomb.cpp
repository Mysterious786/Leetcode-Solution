class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans; 
        }

        vector<int> prefSum(n, 0), suffSum(n, 0);
        prefSum[0] = code[0];
        suffSum[n - 1] = code[n - 1];

        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + code[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffSum[i] = suffSum[i + 1] + code[i];
        }

     
        for (int i = 0; i < n; i++) {
            int tempK = abs(k); 
            if (k > 0) { 
                int start = (i + 1) % n;
                int end = (i + k) % n;

                if (start <= end) {
                    ans[i] = prefSum[end] - (start > 0 ? prefSum[start - 1] : 0);
                } else { 
                    ans[i] = prefSum[n - 1] - (start > 0 ? prefSum[start - 1] : 0) + prefSum[end];
                }
            } else {
                int start = (i - 1 + n) % n;
                int end = (i + k + n) % n;

                if (end <= start) {
                    ans[i] = suffSum[end] - (start < n - 1 ? suffSum[start + 1] : 0);
                } else {
                    ans[i] = suffSum[0] - (start < n - 1 ? suffSum[start + 1] : 0) + suffSum[end];
                }
            }
        }

        return ans;
    }
};
