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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr || (!root->left && !root->right))
            return root;

        auto t = root->left;
        root->left = root->right;
        root->right = t;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
//一个优秀的程序员，算法与数据结构有多重要？
// 我觉得数据结构就相当于：我塞牙了，那么就要用到牙签这“数据结构”，当然你用指甲也行，只不过“性能”没那么好；我要拧螺母，肯定用扳手这个“数据结构”，当然你用钳子也行，只不过也没那么好用。学习数据结构，就是为了了解以后在IT行业里搬砖需要用到什么工具，这些工具有什么利弊，应用于什么场景。以后用的过程中，你会发现这些基础的“工具”也存在着一些缺陷，你不满足于此工具，此时，你就开始自己在这些数据结构的基础上加以改造，这就叫做自定义数据结构。而且，你以后还会造出很多其他应用于实际场景的数据结构。。

// 等到工作了以后做业务系统开发，发现根本就用不到那些书中的讲的二叉树、图、排序算法
// 更重要的是你要学习一种思想：如何把现实问题转化为计算机语言的表示。
// 总结一下，《数据结构》这门课其实会潜移默化的影响你的逻辑思维， 当然， 你需要多多练习才有可能使用纯熟， 等它变成身体一部分以后， 你就发现其实大部分编程任务都没什么难度了，更难的其实是对编程更高的要求：抽象的能力。