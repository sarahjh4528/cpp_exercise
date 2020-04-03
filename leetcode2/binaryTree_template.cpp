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
// Case 1:
        TreeNode *top = new TreeNode(2);
        top->left = new TreeNode(1);
        top->right = new TreeNode(3);
// Case 2:
        TreeNode *top = new TreeNode(5);
        top->left = new TreeNode(1);
        top->right = new TreeNode(4);
        top->right->left = new TreeNode(3);
        top->right->right = new TreeNode(6);
// Case 3:
        TreeNode *top = new TreeNode(10);
        top->left = new TreeNode(5);
        top->right = new TreeNode(15);
        top->right->left = new TreeNode(12);
        top->right->right = new TreeNode(20);
        top->right->left->left = new TreeNode(11);
        top->right->left->right = new TreeNode(14);
#endif
        TreeNode *top = new TreeNode(2);
        top->left = new TreeNode(1);
        top->right = new TreeNode(3);
        return top;
    }

};

int main()
{
    return 0;
}
