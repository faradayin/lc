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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        //to the leaf
        if(root->left == nullptr && root->right == nullptr && root->val == sum) return true;
        return hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val);
    }
};



//什么样的人适合写代码
// 理想的程序员心眼儿不坏（他们从来都不是办公室政治的宠儿，是一群单纯明亮快乐的手艺人），有天真烂漫的好奇心（他们的眼睛里经常闪着「哇，这个是怎么做到的！」），永远精益求精（他们的口头禅是「我再研究一下」），还乐于分享（他们活跃于GitHub、各大问答社区和你的身边，舍得将宝贵时间用于帮助新手）。是的，他们不需要被管理，只需要给一个大的方向，总能回报以意想不到的结果。
// 理想的程序员与平庸的程序员只有一墙之隔。两者的差距只有6个一点点，而人与人的差距，正是在这日积月累的一点点中，被永远拉开了。有意思的是，我发现这6个一点点都和意识有关，也就是程序员和其他一切新兴产业的工种一样，只需要意识加上时间的锤炼，人人皆可达到理想的阶段。理想的程序员必然也是一个优秀的problem-solver

