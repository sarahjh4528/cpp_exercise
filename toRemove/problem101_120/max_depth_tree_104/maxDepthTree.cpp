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
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int leftTreeDp = (root->left)? maxDepth(root->left) : 0;
        int rightTreeDp = (root->right)? maxDepth(root->right) : 0;
        return (max(leftTreeDp, rightTreeDp) + 1);
    }
};

int main()
{
    Solution s;

    TreeNode *top = s.buildTree();
    int maxDp = s.maxDepth(top);
    cout << "Tree max depth : " << maxDp << endl;
    return 0;
}
