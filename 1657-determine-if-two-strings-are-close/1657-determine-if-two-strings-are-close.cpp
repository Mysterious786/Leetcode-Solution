#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if (size1 != size2)
            return false;

        vector<int> v1(26, 0), v2(26, 0);

        for (auto it : word1) {
            v1[it - 'a']++;
        }

        for (auto it : word2) {
            v2[it - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((v1[i] == 0 && v2[i] != 0) || (v1[i] != 0 && v2[i] == 0))
                return false;
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }

        return true;
    }
};
