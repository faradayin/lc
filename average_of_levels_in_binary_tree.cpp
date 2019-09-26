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
    vector<double> averageOfLevels(TreeNode* root) {
        //non-empty
            queue<TreeNode* > q;
            q.push(root);
            vector<double> res;
            while(!q.empty())
            {
                int n = q.size();
                int val = 0;
                for(int i = n;i--;i>0)
                {
                    val += q.front()->val;
                    if(q.front()->left)  q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();

                }
                double ava = (double)val/n;
                res.push_back(ava);

            }
            return res;
    }
};