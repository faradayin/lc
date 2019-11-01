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
//我自己能写出来吗？
//不能
    int pathSum_StartWithRoot(TreeNode* root, int sum)
    {
        if(root == nullptr) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res += pathSum_StartWithRoot(root->left, sum - root->val)+pathSum_StartWithRoot(root->right, sum - root->val);
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int res = pathSum_StartWithRoot(root, sum)+pathSum(root->left, sum)+pathSum(root->right, sum);
        return res;
    }
};
//What do you really want ?
//What kind of life do you want ?
//But this moment is your life !
