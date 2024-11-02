/*
Runtime 0 ms Beats 100.00%
Memory 19.08 MB Beats 68.08%
*/
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
    void solve(TreeNode *root, int targetSum, vector<int>& v, vector<vector<int>>& res) {
        if (!root)
            return;

        v.push_back(root->val);
        if (targetSum == root->val && !root->left && !root->right) {
            res.push_back(v);
        } else {
            solve(root->left, targetSum - root->val, v, res);
            solve(root->right, targetSum - root->val, v, res);
        }
        v.pop_back();
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

    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(5);
        top->left = new TreeNode(4);
        top->right = new TreeNode(8);
        top->left->left = new TreeNode(11);
        top->left->left->left = new TreeNode(7);
        top->left->left->right = new TreeNode(2);
        top->right->left = new TreeNode(13);
        top->right->right = new TreeNode(4);
        top->right->right->left = new TreeNode(5);
        top->right->right->right = new TreeNode(1);
        return top;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        solve(root, targetSum, v, res);
        return res;
    }

};

int main()
{
    Solution s;
    int targetSum = 22;

    cout << "Input tree: " << endl;
    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    vector<vector<int>> output = s.pathSum(root, targetSum);
    cout << "Output vectors: " << endl;
    for (auto v : output) {
        for (auto n : v)
            cout << n << " ";
        cout << ", ";
    }
    cout << endl;

    return 0;
}
