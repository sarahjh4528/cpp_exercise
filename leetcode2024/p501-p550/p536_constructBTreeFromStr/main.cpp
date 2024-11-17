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

    TreeNode* str2tree(string s) {
        
    }

};

int main()
{
    vector<string> vs = {
        "4(2(3)(1))(6(5))",
        "4(2(3)(1))(6(5)(7))",
        "-4(2(3)(1))(6(5)(7))"
    };
    Solution s;

    for (auto str : vs) {
        cout << str << endl;
        TreeNode* root = s.str2tree(str);
        s.printTree(root);
    }

    return 0;
}
