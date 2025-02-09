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

#if 0
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(7);
        top->right = new TreeNode(0);
        top->left->left = new TreeNode(7);
        top->left->right = new TreeNode(-8);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(999);
        top->right = new TreeNode(10250);
        top->right->left = new TreeNode(98693);
        top->right->right = new TreeNode(-89388);
        top->right->right->right = new TreeNode(-32127);
        return top;
    }
#endif

/*
The number of nodes in the tree is in the range [1, 10^4].
-10^5 <= Node.val <= 10^5
*/
    int maxLevelSum(TreeNode* root) {
    }
};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    int output = s.maxLevelSum(root);
    cout << "Level with max sum: " << output << endl;
    return 0;
}
