class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelNodes;
            for(int i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();
                levelNodes.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(!flag) reverse(begin(levelNodes),end(levelNodes));
            ans.push_back(levelNodes);
            flag = !flag;
        }
        return ans;
    }
};