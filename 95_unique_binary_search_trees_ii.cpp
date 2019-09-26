#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

//怎么返回头节点组成的数组?
//答：树结构存储于堆中，node指针在函数之间传递（返回vector<>）
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generateTree(int from, int to)
{
    vector<TreeNode *> res;
    if (from > to || from <= 0 || to <= 0)
    {
        res.push_back(nullptr);
        return res;
    }
    if (from == to)
    {
        TreeNode *node = new TreeNode(from);
        res.push_back(node);
        return res;
    }
    for (int i = from; i <= to; i++)
    {
        vector<TreeNode *> vleft = generateTree(from, i - 1);
        vector<TreeNode *> vright = generateTree(i + 1, to);
        for (int l = 0; l < vleft.size(); l++)
        {
            for (int r = 0; r < vright.size(); r++)
            {
                // bottom-up building the tree
                TreeNode *root = new TreeNode(i);
                root->left = vleft[l];
                root->right = vright[r];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    vector<TreeNode *> v;
    if(n == 0) return v;
    v = generateTree(1, n);
    return v;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        printf("#");
        return;
    }
    printf("%d", root->val);
    printTree(root->left);
    printTree(root->right);
}
int main(int argc, char **argv)
{
    int n = 3;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    vector<TreeNode *> v = generateTrees(n);
    for (int i = 0; i < v.size(); i++)
    {
        printTree(v[i]);
        printf("\n");
    }
    return 0;
}