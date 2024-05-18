class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] != 0) {
                if (i != j) {
                    swap(arr[i], arr[j]);
                }
                i++;
            }
        }
    }
};
