/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void makeParent(TreeNode* root, map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front->left)
            {
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right)
            {
                parent[front->right] = front;
                q.push(front->right);
            }
        }
    }
    void solve(TreeNode* target,map<TreeNode*,bool>& visited,map<TreeNode*,TreeNode*>& parent,vector<int>& ans,int k)
    {
        if(k==0)
        {
            ans.push_back(target->val);
        }
        visited[target] = true;
        if(!visited[target->left] and target->left!=NULL)
        {
            solve(target->left,visited,parent,ans,k-1);
        }
        if(!visited[target->right] and target->right!=NULL)
        {
            solve(target->right,visited,parent,ans,k-1);
        }
        if(!visited[parent[target]] and parent[target]!=NULL)
        {
            solve(parent[target],visited,parent,ans,k-1);
        }
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,bool> visited;
        makeParent(root,parent);
        solve(target,visited,parent,ans,k);
        return ans;
    }
};