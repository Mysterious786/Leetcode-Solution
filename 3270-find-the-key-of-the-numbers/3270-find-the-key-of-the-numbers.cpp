#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string st1 = to_string(num1);
        string st2 = to_string(num2);
        string st3 = to_string(num3);

        // Padding each string to ensure they are exactly 4 characters long
        while (st1.size() < 4) st1 = '0' + st1;
        while (st2.size() < 4) st2 = '0' + st2;
        while (st3.size() < 4) st3 = '0' + st3;

        string s = "";
        for (int i = 0; i < 4; i++) {
            // Find the minimum character at the i-th position across the three strings
            char c = min({st1[i], st2[i], st3[i]});
            s += c;
        }

        // Convert the resulting string s to an integer and return (removes leading zeros)
        return stoi(s);
    }
};
