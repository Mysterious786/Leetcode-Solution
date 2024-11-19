class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int currentPos = q.front();
            q.pop();

            if (arr[currentPos] == 0) {
                return true;
            }

            int forwardPos = currentPos + arr[currentPos];
            int backwardPos = currentPos - arr[currentPos];

            if (forwardPos < n && !vis[forwardPos]) {
                q.push(forwardPos);
                vis[forwardPos] = 1;
            }

            if (backwardPos >= 0 && !vis[backwardPos]) {
                q.push(backwardPos);
                vis[backwardPos] = 1;
            }
        }

        return false;
    }
};
