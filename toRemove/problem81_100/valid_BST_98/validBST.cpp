#include<iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum CHECK_BOUND {
    CHECK_UPPER,
    CHECK_LOWER,
    CHECK_BOTH
};

class Solution
{
public:
    TreeNode* buildTree() {
#if 0
        TreeNode *top = new TreeNode(5);
        top->left = new TreeNode(1);
        top->right = new TreeNode(4);
        top->right->left = new TreeNode(3);
        top->right->right = new TreeNode(6);

        TreeNode *top = new TreeNode(2);
        top->left = new TreeNode(1);
        top->right = new TreeNode(3);
#endif
        TreeNode *top = new TreeNode(5);
        top->left = new TreeNode(3);
        top->right = new TreeNode(7);
        top->right->left = new TreeNode(6);
        top->right->right = new TreeNode(8);
        return top;
    }

    void printTree(TreeNode *top) {
        if (!top)
            return;

        printTree(top->left);
        cout << top->val << " ";
        printTree(top->right);
    }

    bool checkValidBST(TreeNode* root, CHECK_BOUND chCondition, int low, int high) {
        if (!root)
            return true;

        CHECK_BOUND chNextLeft = chCondition, chNextRight = chCondition;
        switch (chCondition) {
            case CHECK_UPPER:
                if (root->val >= high)
                    return false;
                chNextRight = CHECK_BOTH;
                break;
            case CHECK_LOWER:
                if (root->val <= low)
                    return false;
                chNextLeft = CHECK_BOTH;
                break;
            case CHECK_BOTH:
                if (root->val >= high || root->val <= low)
                    return false;
                break;
            default:
                cerr << "Invalid check condition" << endl;
                break;
        }

        return (checkValidBST(root->left, chNextLeft, low, root->val)
                && checkValidBST(root->right, chNextRight, root->val, high));
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return (checkValidBST(root->left, CHECK_UPPER, 0, root->val)
                && checkValidBST(root->right, CHECK_LOWER, root->val, 0));
    }
};

int main()
{
    Solution s;
    TreeNode *treeTop = s.buildTree();
    s.printTree(treeTop);
    cout << endl;
    bool isValid = s.isValidBST(treeTop);
    cout << "Tree is valid BST : " << isValid << endl;
    return 0;
}

