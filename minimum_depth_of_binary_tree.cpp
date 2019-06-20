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
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int Dl = minDepth(root->left);
        int Dr = minDepth(root->right);
        if(Dr == 0 || Dl == 0) return Dl+Dr+1;
        return min(Dl, Dr) + 1;
    }
};