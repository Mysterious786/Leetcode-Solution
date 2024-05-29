class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        if (n == 0) return ""; // Handle empty string case

        string st = "";
        int count = 1;
        char c = word[0];

        for (int i = 1; i < n; i++) {
            if (word[i] == c) {
                if (count < 9) {
                    count++;
                } else {
                    st += to_string(count) + c;
                    count = 1;
                }
            } else {
                st += to_string(count) + c;
                c = word[i];
                count = 1;
            }
        }
        // Append the last character and its count
        st += to_string(count) + c;

        return st;
    }
};
