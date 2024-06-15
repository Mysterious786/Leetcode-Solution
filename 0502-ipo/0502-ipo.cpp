class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort projects based on their capital requirements
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;
        int i = 0;

        while (k-- > 0) {
            // Push all projects that can be started with current capital into the max-heap
            while (i < projects.size() && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                ++i;
            }

            // If there are no projects that can be started, break
            if (maxProfitHeap.empty()) {
                break;
            }

            // Add the most profitable project to the current capital
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};
