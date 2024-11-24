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
        TreeNode *top = new TreeNode(5);
        top->left =  new TreeNode(3);
        top->right =  new TreeNode(6);
        top->left->left =  new TreeNode(2);
        top->left->right =  new TreeNode(4);
        top->right->right =  new TreeNode(7);
        return top;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;
    TreeNode* output = s.deleteNode(root, 3);
    s.printTree(output);
    cout << endl;

    return 0;
}
