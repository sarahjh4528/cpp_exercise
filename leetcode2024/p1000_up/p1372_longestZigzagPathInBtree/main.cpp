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
    // 0: cur left, 1: cur right
    void dfs(TreeNode *root, int dir, int curlen, int& res) {
        if (!root)
            return;
        res = max(res, curlen);
        if (dir == 0) {
            dfs(root->left, 0, 1, res);
            dfs(root->right, 1, curlen+1, res);
        } else {
            dfs(root->left, 0, curlen+1, res);
            dfs(root->right, 1, 1, res);
        }
    }

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

/*
Runtime 4 ms Beats 52.71%
Memory 94.34 MB Beats 90.21%
Same solution as fastest solution

Time: O(n), Space: O(n)
*/
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root->left, 0, 1, res);
        dfs(root->right, 1, 1, res);
        return res;
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
