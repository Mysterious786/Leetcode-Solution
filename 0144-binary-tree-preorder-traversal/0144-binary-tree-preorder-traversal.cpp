class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            auto top = st.top();
            st.pop();
            ans.push_back(top->val);
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
            
        }
        return ans;

    }
};