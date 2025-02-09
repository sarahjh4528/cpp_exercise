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

#if 1
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(3);
        top->left->right = new TreeNode(5);
        top->right->right = new TreeNode(4);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(3);
        top->left->left = new TreeNode(4);
        top->left->left->left = new TreeNode(5);
        return top;
    }
#endif

/*
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
    vector<int> rightSideView(TreeNode* root) {
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    vector<int> output = s.rightSideView(root);
    for (auto i : output)
        cout << i << " ";
    cout << endl;

    return 0;
}
