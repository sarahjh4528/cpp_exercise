#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildUnbalancedTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(2);
        top->left->left = new TreeNode(3);
        top->left->right = new TreeNode(3);
        top->left->left->left = new TreeNode(4);
        top->left->left->right = new TreeNode(4);
        return top;
    }

    TreeNode *buildBalancedTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

    bool isBalancedTree(TreeNode *root, int& treeDepth) {
        if (!root)
            return true;

        int leftTreeDepth = 0, rightTreeDepth = 0;
        if (!isBalancedTree(root->left, leftTreeDepth) ||
            !isBalancedTree(root->right, rightTreeDepth))
            return false;

        treeDepth = treeDepth + max(leftTreeDepth, rightTreeDepth) + 1;
        return (abs(leftTreeDepth - rightTreeDepth) > 1)? false : true;
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int leftTreeDepth = 0, rightTreeDepth = 0;
        if (isBalancedTree(root->left, leftTreeDepth) &&
            isBalancedTree(root->right, rightTreeDepth)) {
            return (abs(leftTreeDepth-rightTreeDepth) > 1)? false : true;
        }
        return false;
    }
};

int main()
{
    Solution s;

    TreeNode *top = s.buildBalancedTree();
    bool isBal = s.isBalanced(top);
    cout << "Balanced tree isBal : " << isBal << endl;

    TreeNode *unBalTop = s.buildUnbalancedTree();
    isBal = s.isBalanced(unBalTop);
    cout << "Unbalanced tree isBal : " << isBal << endl;
    return 0;
}
