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
    bool isSametree(TreeNode* s, TreeNode* t)
    {
        if(s == nullptr && t == nullptr) return true;

        if(s == nullptr || t == nullptr) return false;

        if(s->val != t->val) return false;

        return isSametree(s->left, t->left) && isSametree(s->right, t->right);
    }

public:
    //whether t is a sub-tree of s ?
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr) return false;
        return isSametree(s, t)||isSubtree(s->left, t)||isSubtree(s->right, t);
    }
};
