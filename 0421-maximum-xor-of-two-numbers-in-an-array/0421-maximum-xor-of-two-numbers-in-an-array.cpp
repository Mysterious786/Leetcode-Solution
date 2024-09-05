#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];  // We use 2 instead of 26 since we only need 0 and 1 for binary numbers

    Node() {
        links[0] = links[1] = nullptr;  // Initialize pointers to nullptr
    }

    bool containKey(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMaximum(int num) {
        Node* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggledBit = bit ^ 1;  // Try to find the opposite bit for maximizing XOR
if (node->containKey(toggledBit)) {
    maxXor += (1 << i);  // Add to the result as this bit contributes to maximizing XOR
    node = node->get(toggledBit);
} else {
    node = node->get(bit);
}

        }
        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxXor = 0;
        for (int num : nums) {
            trie.insert(num);
        }
        for (int num : nums) {
            maxXor = max(maxXor, trie.findMaximum(num));
        }
        return maxXor;
    }
};

