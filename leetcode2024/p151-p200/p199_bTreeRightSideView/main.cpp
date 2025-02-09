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

Runtime 0 ms Beats 100.00%
Memory 14.90 MB Beats 84.60%

Time: O(n), Space: O(n)
*/
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cn = q.front();
                q.pop();
                if (i == size-1)
                    res.push_back(cn->val);
                if (cn->left)
                    q.push(cn->left);
                if (cn->right)
                    q.push(cn->right);
            }
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

    vector<int> output = s.rightSideView(root);
    for (auto i : output)
        cout << i << " ";
    cout << endl;

    return 0;
}
