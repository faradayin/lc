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
//利用队列找到最后一行的最左左node
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        TreeNode* t;
        q.push(root);
        while(!q.empty())
        {
            t = q.front();
            if(q.front()->right) q.push(q.front()->right);
            if(q.front()->left)  q.push(q.front()->left);
            //从右往左入队
            
            q.pop();
        }
        return t->val;
    }
};