class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int row1 = c1[0] -'0';
        int col1 = c1[1] - 'a';
        int row2 = c2[0] -'0';
        int col2 = c2[1] - 'a';
     return ((row1 + col1) % 2 == (row2 + col2) % 2);
    }
};