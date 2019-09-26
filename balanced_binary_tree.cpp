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
    bool res = true;
    int height_of(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int l = height_of(root->left);
        int r = height_of(root->right);
        if(l-r>1 || l-r<-1)
        {
            res = false;
        }
        return max(l,r)+1;
    }


public:
    bool isBalanced(TreeNode* root) {
        height_of(root);
        return res;
    }
};