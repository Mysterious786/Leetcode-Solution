#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void generate(int n, string current, vector<string>& result) {
        if (n == 0) {
            result.push_back(current);
            return;
        }

        if (current.empty() || current.back() == '1') {
            generate(n - 1, current + '0', result);
        }
        generate(n - 1, current + '1', result);
    }

public:
    vector<string> validStrings(int n) {
        vector<string> result;
        generate(n, "", result);
        return result;
    }
};
