class Solution {
public:
vector<TreeNode*> last;
TreeNode* recoverFromPreorder(string traversal) {
last.resize(1000);
int count = 0;
for(int i = 0 ; i < traversal.size() ; )
{
int num = 0;
while(traversal[i] != '-' && i < traversal.size())
num = num * 10 + (traversal[i++] - '0');
TreeNode* node = new TreeNode(num);
last[count] = node;
if(count != 0) // count stores the level at which node is located, root is at level 0
{
TreeNode* parent = last[count - 1];
if(parent -> left)
parent -> right = node;
else
parent -> left = node;
}
count = 0;
while(i < traversal.size() && traversal[i] == '-')
count ++, i++;
}
return last[0];
}