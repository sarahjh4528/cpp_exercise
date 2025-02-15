#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(...);
        return top;
    }

/*
The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 10^7
root is a binary search tree.
1 <= val <= 10^7
*/
/*
Recursive solution

Runtime 0 ms Beats 100.00%
Memory 35.44 MB Beats 61.09%
*/
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }

/*
Iterative solution
Runtime 0 ms Beats 100.00%
Memory 35.42 MB Beats 61.09%
*/
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);

    return 0;
}
