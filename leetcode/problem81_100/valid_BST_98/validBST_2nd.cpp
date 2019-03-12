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
        top->right->left = new TreeNode(5);
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

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
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

