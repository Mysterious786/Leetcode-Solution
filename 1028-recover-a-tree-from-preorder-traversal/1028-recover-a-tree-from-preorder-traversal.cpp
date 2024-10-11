
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> last(1000);
        int n = size(traversal);
        int count = 0;
        for(int i=0;i<n;)
        {
            int num = 0;
            while(i<n and traversal[i]!='-')
            {
                num = num*10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(num);
            last[count] = node;
            if(count!=0)
            {
                TreeNode* parent = last[count-1];
                
                if(parent->left)
                {
                    parent->right = node;
                }
                else parent->left = node;
            }
            count = 0;
            while(i<n and traversal[i] == '-') count++,i++;

        }
        return last[0];
    }
};



















