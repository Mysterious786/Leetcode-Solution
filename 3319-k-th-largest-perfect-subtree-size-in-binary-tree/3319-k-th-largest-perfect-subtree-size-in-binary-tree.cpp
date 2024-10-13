class Solution {
private:

    int count(TreeNode* root,priority_queue<int>& pq)
    {
        if(root == NULL) return 0;
        int left = count(root->left,pq);
        int right = count(root->right,pq);
        if(left == -1 || right == -1) return -1;
        if(left == right) {
            pq.push(1+left+right);
        
        return 1+left+right;
        }
        return -1;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int> pq;
        int tot =  count(root,pq);
        k--;
        while(k-- and !pq.empty()) pq.pop();
        if(pq.empty()) return -1;
        return pq.top();
    }
};