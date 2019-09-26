/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  相同节点值的最大路径长度
//  路径定义为：任意两个node之间的边的个数
class Solution {
private:
    int uniPath(TreeNode* root, int &res)
    {
        if(root == nullptr) return 0;
        int len_l = uniPath(root->left, res);
        int len_r = uniPath(root->right, res);

        int lp = root->left && root->val == root->left->val ? len_l+1:0;
        int lr = root->right&& root->val == root->right->val ? len_r+1:0;

        res = max(res, lp+lr);
        return max(lp, lr);

    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        uniPath(root, res);
        return res;
    }

};