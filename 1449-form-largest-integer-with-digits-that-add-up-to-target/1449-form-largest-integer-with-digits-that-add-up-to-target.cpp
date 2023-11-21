class Solution
{
    private:
        string maxi(string &a, string &b)
        {
            if (a.back() == '0') return b;
            else if (b.back() == '0') return a;
            else if (size(a) == size(b))
                return max(a, b);
            else if (size(a) > size(b)) return a;
            else return b;
        }
    string helper(int ind, int n, vector<int> &cost, int target, vector<vector< string>> &dp)
    {
        if (target == 0) return "";
        if (ind >= n || target < 0) return "0";
        if (dp[ind][target] != "-1") return dp[ind][target];

        string pick = to_string(ind + 1) + helper(0, n, cost, target - cost[ind], dp);
        string notPick = helper(ind + 1, n, cost, target, dp);

        return dp[ind][target] = maxi(pick, notPick);
    }
    public:
        string largestNumber(vector<int> &cost, int target)
        {
            int n = cost.size();
            vector<vector < string>> dp(n + 1, vector<string> (target + 1, "-1"));
            string s = helper(0, n, cost, target, dp);

            return s;
        }
};