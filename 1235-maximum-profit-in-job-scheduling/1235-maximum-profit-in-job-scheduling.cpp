#include <vector>
#include <algorithm>

#define ll long long

struct Job {
    int startDate = 0;
    int endDate = 0;
    int profit = 0;
};

class Solution {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& reward) {
        int n = startTime.size();
        std::vector<Job> Schedule(n);

        for (int i = 0; i < n; i++) {
            Schedule[i].startDate = startTime[i];
            Schedule[i].endDate = endTime[i];
            Schedule[i].profit = reward[i];
        }

        std::sort(Schedule.begin(), Schedule.end(), [](const Job& p1, const Job& p2) {
            return p1.endDate < p2.endDate;
        });

        std::vector<int> endi(n + 1);
        for (int i = 1; i <= n; i++) {
            endi[i] = Schedule[i - 1].endDate; // Corrected indexing
        }

        std::vector<ll> maxMoney(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int j = std::distance(endi.begin(), std::upper_bound(endi.begin(), endi.end(), Schedule[i - 1].startDate)) - 1; // Corrected indexing
            maxMoney[i] = std::max(maxMoney[i - 1], maxMoney[j] + Schedule[i - 1].profit); // Corrected indexing
        }

        return static_cast<int>(maxMoney[n]);
    }
};

