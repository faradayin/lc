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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node != nullptr || !stk.empty())
        {
            while (node != nullptr)
            {
                stk.push(node);
                node = node->left;
            }

            node = stk.top();
            res.push_back(node->val);
            stk.pop();
            node = node->right;
        }
        return res;
    }
};
//之前练手写的
// void InOrderDev(TreeNode *root)
// {
//     if (root == nullptr)
//         return;
//     stack<TreeNode *> nstack;
//     TreeNode *node = root;

//     //start traversing
//     while (node != nullptr || !nstack.empty())
//     {
//         while (node != nullptr)
//         {
//             //push root node
//             //to the most left node
//             nstack.push(node);
//             node = node->left;
//         }

//         //now the most left node is on the top of nstack
//         //pop it out
//         //start traversing its right-subtree
//         if (!nstack.empty())
//         {
//             node = nstack.top();
//             cout << node->val;
//             nstack.pop();
//             node = node->right;
//         }
//     }
// }