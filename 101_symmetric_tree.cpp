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
    bool isSym(TreeNode* l, TreeNode* r)
    {
        if(l == nullptr && r == nullptr) return true;
        if(l == nullptr || r == nullptr) return false;

        if(l->val != r->val) return false;

        return isSym(l->left, r->right) && isSym(l->right, r->left);

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSym(root->left, root->right);

    }
};
//solution