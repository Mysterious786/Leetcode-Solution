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
private:
    vector<int> adj[100005];

    void f(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        f(root->left);
        f(root->right);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        queue<int> q;
        f(root);
        const int size = 100005; // Match the size with the adj array
        int vis[size] = {0};
        int ans = 0;
        q.push(start);

        while (!q.empty()) {
            int levelSize = q.size(); // Store the initial size
            ans++;

            for (int i = 0; i < levelSize; i++) {
                int val = q.front();
                q.pop();
                vis[val] = 1;

                for (auto it : adj[val]) {
                    if (!vis[it]) {
                        q.push(it);
                    }
                }
            }
        }

        return ans - 1;
    }
};
