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
    //超时
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int val0 = root->val;
        if (root->left)
            val0 += (rob(root->left->left) + rob(root->left->right));
        if (root->right)
            val0 += (rob(root->right->left) + rob(root->right->right));
        int val1 = rob(root->left) + rob(root->right);
        return max(val0, val1);
    }

private:
    //别人写的,看不懂
    vector<int> robSub(TreeNode *root)
    {
        vector<int> res(2,0);
        if(root == nullptr) return res;

        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];

        return res;
    }

public:
    int rob(TreeNode *root)
    {
        vector<int> result = robSub(root);

        return max(result[0], result[1]);
    }
};
// Let

// f1(node) be the value of maximum money we can rob from the subtree with node as root ( we can rob node if necessary).

// f2(node) be the value of maximum money we can rob from the subtree with node as root but without robbing node.

// Then we have

// f2(node) = f1(node.left) + f1(node.right) 

// f1(node) = max( f2(node.left)+f2(node.right)+node.value, f2(node) )

class Solution {
public:
    int rob(TreeNode* root) {
        return robDFS(root).second;
    }
    pair<int, int> robDFS(TreeNode* node){
        if( !node) return make_pair(0,0);
        auto l = robDFS(node->left);
        auto r = robDFS(node->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + node->val);
        return make_pair(f2, f1);
    }
};