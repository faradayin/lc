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
//后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode *node;
        TreeNode *pre = nullptr;
        while(!stk.empty())
        {
            node = stk.top();
            if(node->left == nullptr && node->right == nullptr || pre != nullptr && (pre == node->right || (pre == node->left && node->right == nullptr ))) 
            {
                res.push_back(node->val);
                stk.pop();
                pre = node;
            }
            else
            {
                if(node->right) stk.push(node->right);
                if(node->left) stk.push(node->left);
            }
            
        }
        return res;
        
    }
};
// 之前练手的后序遍历
// void PostOrderDev(TreeNode* root)
// {
//     if(root == nullptr)
//         return;
//     stack<TreeNode*> nstack;
//     TreeNode* cur;
//     TreeNode* pre = nullptr;
//     nstack.push(root);

//     while(!nstack.empty())
//     {
//         cur = nstack.top();
//         if((cur->left == nullptr && cur->right == nullptr)//both left-child and right-child are null
//         || (pre != nullptr && ((pre == cur->left && cur->right ==nullptr)||pre = cur->right)))//left-child just visited and right-child is null / just visited right child
//         {
//             cout<<cur->val;
//             nstack.pop();
//             pre = cur;
//         }
//         else
//         {
//             if(cur->right != nullptr)
//                 nstack.push(cur->right);
//             if(cur->left != nullptr)
//                 nstack.push(cur->left);
            
//         }

//     }
// }