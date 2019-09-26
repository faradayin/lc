/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    //先序遍历
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            if (stk.top() == nullptr)
            {
                stk.pop();
                continue;
            }
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            stk.push(node->right);
            stk.push(node->left);
        }
        return res;
    }

//null node不允许入栈的版本
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return res;
    }
};