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
    int maxval = 0;//update this val during recursion 
    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        maxval = max(maxval, l+r);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxval;
    }
};