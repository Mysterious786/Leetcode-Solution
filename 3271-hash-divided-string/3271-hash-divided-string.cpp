#include <string>
using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        string result = "";

        // Iterate over the string, processing each substring of length k
        for (int i = 0; i < n; i += k) {
            int sum = 0;

            // Calculate the sum of hash values for the current substring
            for (int j = i; j < i + k; j++) {
                sum += (s[j] - 'a');
            }

            // Find the remainder when the sum is divided by 26
            int hashedChar = sum % 26;

            // Convert the remainder to a corresponding character
            char ch = 'a' + hashedChar;

            // Append the character to the result string
            result += ch;
        }

        return result;
    }
    
};
