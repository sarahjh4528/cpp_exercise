/**
 * Binary Search Tree Node
 * Recursive solution & loop solution: both 16ms, faster than 65%, 20.6MB, less than 91%
 */
#include<iostream>
#include<stack>

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

#if 0
    // Recursive solution: faster than 65.48%.
    bool helper(TreeNode *root, TreeNode *lower, TreeNode *upper) {
        if (root == nullptr)
            return true;
        if (lower && root->val <= lower->val) return false;
        if (upper && root->val >= upper->val) return false;
        return helper(root->left, lower, root) && helper(root->right, root, upper);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
#else
    // Loop solution: Depth first search to get lowest limit.
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        TreeNode *lower = nullptr;
        while (!treeStack.empty()) {
            while (root->left) {
                treeStack.push(root->left);
                root = root->left;
            }
            TreeNode *node = treeStack.top();
            treeStack.pop();
            //cout << "node->val:" << node->val << endl;
            if (lower && lower->val >= node->val)
                return false;
            lower = node;
            //cout << "New lower->val:" << lower->val << endl;
            if (node->right) {
                treeStack.push(node->right);
                root = node->right;
            }
        }
        return true;
    }
#endif
};

int main()
{
    Solution s;
    TreeNode *head = s.buildTree();
    bool isBST = s.isValidBST(head);
    cout << "Is valid BST: " << isBST << endl;
    return 0;
}
