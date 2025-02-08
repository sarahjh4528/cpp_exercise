#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void printTree(TreeNode *t) {
        if (!t) {
            cout << " null";
            return;
        }
        cout << " " << t->val;
        printTree(t->left);
        printTree(t->right);
    }

#if 0
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(5);
        top->right = new TreeNode(1);
        top->left->left = new TreeNode(6);
        top->left->right = new TreeNode(2);
        top->left->right->left = new TreeNode(7);
        top->left->right->right = new TreeNode(4);
        top->right->left = new TreeNode(0);
        top->right->right = new TreeNode(8);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        return top;
    }

#endif

/*
Constraints:

The number of nodes in the tree is in the range [2, 105].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

#if 0
    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;

    TreeNode *p = root->left;
    TreeNode *q = root->right;
#else
    TreeNode *p = root;
    TreeNode *q = root->left;
#endif
    TreeNode* output = s.lowestCommonAncestor(root, p, q);
    cout << "Output val : " << output->val << endl;

    return 0;
}
