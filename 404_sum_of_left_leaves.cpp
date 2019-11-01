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
    int res;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum_of_lls(root);
        return res;
    }
    void sum_of_lls(TreeNode* root)
    {
        if(root == nullptr) return;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) 
        {
            res += root->left->val;
            sum_of_lls(root->right);

        }
            
        else
        {
            sum_of_lls(root->left);
            sum_of_lls(root->right);
        }
        return;
    }
};