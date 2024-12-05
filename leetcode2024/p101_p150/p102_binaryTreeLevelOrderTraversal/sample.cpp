#include<bits/stdc++.h>
#include<iostream>
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

    TreeNode* buildTree() {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        return root;
    }

/*
Runtime 0 ms Beats 100.00%
Memory 17.13 MB Beats 5.03%
*/
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int qsize = q.size();
            vector<int> cur;
            for (int i = 0; i < qsize; i++) {
                auto n = q.front();
                q.pop();
                cur.push_back(n->val);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            res.push_back(cur);
        }
        return res;
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;
    vector<vector<int>> output = s.levelOrder(root);
    for (auto row : output) {
        for (auto n : row)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
