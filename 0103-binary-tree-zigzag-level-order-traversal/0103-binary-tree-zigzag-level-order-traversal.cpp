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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        bool flag = true;
        while(!q.empty()){
            vector<int> v;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto it = q.front();
                q.pop();
                v.push_back(it->val);
                if(it->left!=NULL) q.push(it->left);
                if(it->right!=NULL) q.push(it->right);
            }
            if(!flag) reverse(v.begin(),v.end());
            ans.push_back(v);
            flag=!flag;
            
        }
        return ans;
        
    }
};