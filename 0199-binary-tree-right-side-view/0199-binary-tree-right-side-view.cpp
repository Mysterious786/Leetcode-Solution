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
        if(root == NULL) return {};
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<int> ans;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            auto node = front.first;
            int level = front.second;
            mp[level] = node->val;
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};