class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        
        // Compute prefix XOR
        for(int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];
        }
        
        // Iterate through all possible triplets (i, j, k)
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                // Check for triplet condition
                if(arr[j] == (i > 0 ? arr[i - 1] : 0)) {
                    ans += j - i;
                }
            }
        }
        
        return ans;
    }
};
