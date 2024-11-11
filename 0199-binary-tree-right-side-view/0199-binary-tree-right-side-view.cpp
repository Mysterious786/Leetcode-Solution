/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;  // Handle case where root is NULL
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, int> mp;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int lev = front.second;

            mp[lev] = node->val;  // Update the value at each level with the rightmost node
            
            // Push the left and right children with incremented level
            if (node->left) q.push({node->left, lev + 1});
            if (node->right) q.push({node->right, lev + 1});
        }

        for (auto it : mp) ans.push_back(it.second);
        return ans;
    }
};
