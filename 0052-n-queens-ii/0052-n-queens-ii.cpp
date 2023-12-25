class Solution {
    private:
    void find(int row, int n, vector<bool>& l, vector<bool>& r, vector<bool>& c, vector<vector<string>>& ans, vector<string>& st) {
        if (row == n) {
            ans.push_back(st);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!l[row - i + n - 1] && !c[i] && !r[row + i]) {
                st[row][i] = 'Q';
                l[row - i + n - 1] = c[i] = r[row + i] = true;
                find(row + 1, n, l, r, c, ans, st);
                l[row - i + n - 1] = c[i] = r[row + i] = false;
                st[row][i] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
         vector<string> st;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++)
                s += '.';
            st.emplace_back(s);
        }

        vector<vector<string>> ans;
        vector<bool> left(2 * (n - 1)+5), right(2 * (n - 1)+5);
        vector<bool> col(n);

        find(0, n, left, right, col, ans, st);

        return ans.size();
    }
};



