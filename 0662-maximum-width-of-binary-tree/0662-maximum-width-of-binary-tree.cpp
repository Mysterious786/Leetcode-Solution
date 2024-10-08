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
#define l size_t
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,l>> q;
        l ans = 1;
        q.push({root,0ll});
        while(!q.empty())
        {
            l sz = q.size();
            ans = max(ans,q.back().second-q.front().second+1);
            for(l i=0;i<sz;i++)
            {
                auto front = q.front();
                auto node = front.first;
                l ind = front.second;
                q.pop();
                if(node->left)
                {
                    q.push({node->left,2ll*ind+1ll});
                }
                if(node->right)
                {
                    q.push({node->right,2ll*ind+2ll});
                }
            }
        }
        return static_cast<int>(ans);
    }
};