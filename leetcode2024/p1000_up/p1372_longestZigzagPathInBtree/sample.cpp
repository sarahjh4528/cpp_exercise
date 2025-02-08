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
        top->right = new TreeNode(2);
        top->right->left = new TreeNode(3);
        top->right->right = new TreeNode(3);
        top->right->right->left = new TreeNode(4);
        top->right->right->right = new TreeNode(4);
        top->right->right->left->right = new TreeNode(5);
        top->right->right->left->right->right = new TreeNode(6);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(2);
        top->left->right = new TreeNode(3);
        top->left->right->left = new TreeNode(4);
        top->left->right->right = new TreeNode(4);
        top->left->right->left->right = new TreeNode(5);
        return top;
    }
#endif

    int longestZigZag(TreeNode* root) {
    }
};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    int output = s.longestZigZag(root);
    cout << "Longest zigzag path len: " << output << endl;

    return 0;
}
