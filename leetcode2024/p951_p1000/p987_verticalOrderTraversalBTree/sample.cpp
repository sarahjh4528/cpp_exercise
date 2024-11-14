#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<queue>

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
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(3);
        top->left->left = new TreeNode(4);
        top->left->right = new TreeNode(6);
        top->right->left = new TreeNode(5);
        top->right->right = new TreeNode(7);
        return top;
    }
    
#endif

    vector<vector<int>> verticalTraversal(TreeNode* root) {
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    vector<vector<int>> output = s.verticalTraversal(root);
    for (auto row : output) {
        for (auto v : row)
            cout << v << " ";
        cout << ", ";
    }
    cout << endl;

    return 0;
}
