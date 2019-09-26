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
//时间超限
    int rob(TreeNode* root) {
        
        if(root == nullptr) return 0;
        int val0 = root->val;
        if(root->left) val0+=(rob(root->left->left)+rob(root->left->right));
        if(root->right) val0+=(rob(root->right->left)+rob(root->right->right));
        int val1 = rob(root->left)+rob(root->right);
        return max(val0,val1);
    }


};
// 递归：
// 总结递归关系
// 递归最终都是从低层开始计算、返回
// 必要时传引用/使用全局变量
