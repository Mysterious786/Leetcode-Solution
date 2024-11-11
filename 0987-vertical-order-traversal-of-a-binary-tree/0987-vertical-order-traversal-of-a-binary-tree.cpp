class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0},root});

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int col = front.first.first;
            int row = front.first.second;
            TreeNode* node = front.second;
            mp[col][row].insert(node->val);
            if(node->left) q.push({{col-1,row+1},node->left});
            if(node->right) q.push({{col+1,row+1},node->right});
        }
        for(auto it : mp)
        {
            vector<int> v;
            for(auto i : it.second)
            {
                v.insert(v.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};