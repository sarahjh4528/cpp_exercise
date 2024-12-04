/*
Constraints:

1 <= n <= 19
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

    int numTrees(int n) {
    }

};

int main()
{
    vector<int> vn = {3, 1};
    Solution s;

    for (auto n : vn) {
        int output = s.numTrees(n);
        cout << "Num of unique trees with " << n  << " nodes : " << output << endl;
    }

    return 0;
}
