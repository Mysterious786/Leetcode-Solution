class Solution {
public:
    bool isPalindrome(int x) {
        string st = to_string(x);
        string y = st;
        reverse(begin(y),end(y));
        return y==st;
    }
};