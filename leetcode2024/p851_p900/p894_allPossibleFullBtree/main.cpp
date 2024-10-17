/*
Runtime 60 ms Beats 63.75%
Memory 32.28 MB Beats 80.40%
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
    unordered_map<int, vector<TreeNode*>> memo;
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

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) // Even number of nodes can't format full binary tree
            return {};

        if (n == 1)
            return {new TreeNode(0)};

        if (memo.count(n))
            return memo[n];

        vector<TreeNode*> res;
        for (int i = 1; i < n; i+=2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1); // Additional -1 is for root.

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode *root = new TreeNode(0, l, r);
                    res.push_back(root);
                }
            }
        }
        memo[n] = res;
        return res;
    }
};

int main()
{
    vector<int> input = {7, 3};
    Solution s;

    for (auto n : input) {
        cout << "n = " << n << endl;
        vector<TreeNode*> output = s.allPossibleFBT(n);
        for (auto tree : output)
            s.printTree(tree);
            cout << endl;
    }

    return 0;
}
