/**
 * Binary tree node
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree() {
#if 0
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(2);
        top->left->left = new TreeNode(3);
        top->left->right = new TreeNode(4);
        top->right->left = new TreeNode(4);
        top->right->right = new TreeNode(3);
#else
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(2);
        top->left->right = new TreeNode(3);
        top->right->right = new TreeNode(3);
#endif
        return top;
    }
    bool isSymmetric(TreeNode* root) {

    }

};

int main()
{
    Solution s;
    TreeNode *tree = s.buildTree();
    bool isSymm = s.isSymmetric(tree);
    cout << "Tree is symmetric: " << isSymm << endl;
    return 0;
}
