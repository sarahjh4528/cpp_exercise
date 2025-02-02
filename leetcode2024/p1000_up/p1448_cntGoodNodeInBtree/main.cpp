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
    void dfs(TreeNode *root, int curMax, int& res) {
        if (!root)
            return;
        if (root->val >= curMax) {
            curMax = root->val;
            res++;
        }
        dfs(root->left, curMax, res);
        dfs(root->right, curMax, res);
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
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(1);
        top->right = new TreeNode(4);
        top->left->left = new TreeNode(3);
        top->right->left = new TreeNode(1);
        top->right->right = new TreeNode(5);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(3);
        top->left->left = new TreeNode(4);
        top->left->right = new TreeNode(2);
        return top;
    }
#endif

/*
The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
*/
/*
Runtime 103 ms Beats 37.22%
Memory 88.34 MB Beats 60.83%

Fastest solution has same design
Time: O(N), N : number of nodes
Space: O(N)
*/
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    int output = s.goodNodes(root);
    cout << "Num of good nodes: " << output << endl;

    return 0;
}
