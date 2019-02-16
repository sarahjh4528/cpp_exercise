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
        TreeNode *top = new TreeNode(5);
        top->left = new TreeNode(4);
        top->right = new TreeNode(8);
        top->left->left = new TreeNode(11);
        top->left->left->left = new TreeNode(7);
        top->left->left->right = new TreeNode(2);
        top->right->left = new TreeNode(13);
        top->right->right = new TreeNode(4);
        top->right->right->right = new TreeNode(1);
        return top;
    }
#endif
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        return top;
    }

    bool getPathSum(TreeNode *top, int sum, int depthSum) {
        if (!top)
            return (sum == depthSum)? true : false;

        if (!top->left && !top->right)
            return (top->val + depthSum == sum)? true : false;

        if (!top->left)
            return getPathSum(top->right, sum, depthSum + top->val);

        if (!top->right)
            return getPathSum(top->left, sum, depthSum + top->val);

        return (getPathSum(top->left, sum, depthSum + top->val) ||
                getPathSum(top->right, sum, depthSum + top->val));
    }

    bool hasPathSum(TreeNode *top, int sum) {
        if (!top)
            return false;

        return getPathSum(top, sum, 0);
    }
};

int main()
{
    Solution s;
    TreeNode *treeTop = s.buildTree();
#if 0
    int hasSum = s.hasPathSum(treeTop, 22);
    int hasSum = s.hasPathSum(treeTop, 20);
#endif
    int hasSum = s.hasPathSum(treeTop, 1);
    cout << "Tree has path sum: " << hasSum << endl;
    return 0;
}
