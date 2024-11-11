class Solution {
public:
    //val
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> levelNodes;
            for(int i=0;i<sz;i++)
            {
                auto node = q.front();
                q.pop();
                levelNodes.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);


            }
            ans.push_back(levelNodes);
        }
        return ans;
    }
};