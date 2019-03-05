#include<iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void printTreeInOrder(TreeNode *top) {
        if (!top)
            return;

        if (top->left)
            printTreeInOrder(top->left);

        cout << top->val << " ";

        if (top->right)
            printTreeInOrder(top->right);
    }

    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(4);
        top->left = new TreeNode(2);
        top->right = new TreeNode(7);
        top->left->left = new TreeNode(1);
        top->left->right = new TreeNode(3);
        top->right->left = new TreeNode(6);
        top->right->right = new TreeNode(9);
        return top;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return root;

        TreeNode* saveLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(saveLeft);
        return root;
    }
};

int main()
{
    Solution s;

    TreeNode *top = s.buildTree();
    cout << "Before invert: " << endl;
    s.printTreeInOrder(top);
    cout << endl;
    TreeNode *invertedTree = s.invertTree(top);
    cout << "After invert: " << endl;
    s.printTreeInOrder(invertedTree);
    cout << endl;
    return 0;
}
