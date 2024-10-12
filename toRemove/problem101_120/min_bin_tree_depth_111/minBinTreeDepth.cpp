#include<iostream>

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
#if 0
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        return top;
    }
#endif
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return (minDepth(root->right) + 1);
        if (!root->right) return (minDepth(root->left) + 1);

        return (min(minDepth(root->left), minDepth(root->right)) + 1);
    }
};
int main()
{
    Solution s;
    TreeNode *treeTop = s.buildTree();
    int minDp = s.minDepth(treeTop);
    cout << "Minimum depth: " << minDp << endl;
    
    return 0;
}
