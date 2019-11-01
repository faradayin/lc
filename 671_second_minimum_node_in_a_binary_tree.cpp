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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        if(root->left == nullptr) return -1;
        int left_val = root->left->val;
        int right_val = root->right->val;
        if(left_val == root->val)  left_val = findSecondMinimumValue(root->left);//左边小
        if(right_val == root->val) right_val = findSecondMinimumValue(root->right);//右边小
        if(left_val != -1 && right_val != -1) return min(left_val, right_val);
        if(left_val == -1) return right_val;
        return left_val;
    }
};